/*
Moura's Keyboard Scanner: turn you broken (or unused) keyboard in a MIDI controller
Copyright (C) 2017 Daniel Moura <oxe@oxesoft.com>

This code is originally hosted at https://github.com/oxesoft/keyboardscanner

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <DIO2.h> // install the library DIO2
#define KEYS_NUMBER 61
#define KEY_OFF 0
#define KEY_START 1
#define KEY_ON 2
#define KEY_RELEASED 3

#define PEDAL_SUS 21

//POTENCIOMETROS
const int N_POTS = 3; //* número total de pots (slide e rotativo)
const int POT_ARDUINO_PIN[N_POTS] = {A0, A1, A2}; //* pinos de cada pot conectado diretamente ao Arduino
int potCState[N_POTS] = {0}; // estado atual da porta analogica
int potPState[N_POTS] = {0}; // estado previo da porta analogica
int potVar = 0; // variacao entre o valor do estado previo e o atual da porta analogica
int midiCState[N_POTS] = {0}; // Estado atual do valor midi
int midiPState[N_POTS] = {0}; // Estado anterior do valor midi
const int TIMEOUT = 300; //* quantidade de tempo em que o potenciometro sera lido apos ultrapassar o varThreshold
const int varThreshold = 100; //* threshold para a variacao no sinal do potenciometro
boolean potMoving = true; // se o potenciometro esta se movendo
unsigned long PTime[N_POTS] = {0}; // tempo armazenado anteriormente
unsigned long timer[N_POTS] = {0}; // armazena o tempo que passou desde que o timer foi zerado
boolean pit =false;
boolean mod=false;

byte cc = 1; //* O mais baixo MIDI CC a ser usado
void potentiometers() {


 /* //Debug somente
     for (int i = 0; i < N_POTS; i++) {
      //Serial.print(potCState[i]); Serial.print(" ");
      Serial.print(midiCState[i]); Serial.print(" ");
     }
    Serial.println();
    */

 for (int i = 0; i < N_POTS; i++) { // Faz o loop de todos os potenciômetros

    potCState[i] = analogRead(POT_ARDUINO_PIN[i]);
 
    if(i==0){
    midiCState[i] = map(potCState[i], 450, 880, 0, 127); // Mapeia a leitura do potCState para um valor utilizável em midi
    }
    if(i==1){
    midiCState[i] = map(potCState[i], 215, 795, 0, 127);  
    }
    if(i==2){ 
    midiCState[i] = map(potCState[i], 0, 1023, 0, 127); 
    }

    potVar = abs(potCState[i] - potPState[i]); // Calcula o valor absoluto entre a diferença entre o estado atual e o anterior do pot

    if (potVar > varThreshold) { // Abre o portão se a variação do potenciômetro for maior que o limite (varThreshold)
      PTime[i] = millis(); // Armazena o tempo anterior
    }

    timer[i] = millis() - PTime[i]; // Reseta o timer 11000 - 11000 = 0ms

    if (timer[i] < TIMEOUT) { // Se o timer for menor que o tempo máximo permitido, significa que o potenciômetro ainda está se movendo
      potMoving = true;
    }
    else {
      potMoving = false;
    }

    if (potMoving == true) { // Se o potenciômetro ainda estiver em movimento, envie control change
      if (midiPState[i] != midiCState[i]) {
         if(i==0){// reservado para modulation wheel  
         send_midi_eventcc(0xB0, cc+ i, midiCState[i]);
         mod=false;
         }
         if(i==1){//reservado para pitchbend
         send_midi_eventcc(0xE0, cc+ i, midiCState[i]);
         pit=false;
         }
         if(i==2){
          
         send_midi_eventcc(0xB0, 7, midiCState[i]); 
         }
        potPState[i] = potCState[i]; // Armazena a leitura atual do potenciômetro para comparar com a próxima
        midiPState[i] = midiCState[i];
      }
    }
    if(potMoving==false){
      if(midiCState[1]>55  && midiCState[1]<66 && pit==false){
      midiCState[1]=64;
      send_midi_eventcc(0xE0, 1, midiCState[1]);
      pit=true;
    }
    if(midiCState[0]<10 && mod ==false){
      midiCState[0]=0;
      send_midi_eventcc(0xB0, 1, midiCState[0]);
      mod=true;
    }
    }    
  }
}


#define MIN_TIME_MS 3000
#define MAX_TIME_MS 30000
//20000 até 80000     entre foi melhor até agora3000  40000 
#define MAX_TIME_MS_N (MAX_TIME_MS - MIN_TIME_MS)


//find out the pins using a multimeter, starting from the first key
//see the picture key_scheme.png to understand how to map the inputs and outputs

//the following configuration is specific for PSR530
//thanks Leandro Meucchi, from Argentina, by the PDF
//take a look at the scheme detailed in PSR530.pdf and modify the following mapping according to the wiring of your keyboard
#define PIN_A1  22
#define PIN_A2  23
#define PIN_A3  24
#define PIN_A4  25
#define PIN_A5  26
#define PIN_A6  27
#define PIN_A7  28
#define PIN_A8  29
#define PIN_A9  30
#define PIN_A10 31
#define PIN_A11 32
#define PIN_A12 33

#define PIN_B1  40
#define PIN_B2  41
#define PIN_B3  42
#define PIN_B4  43
#define PIN_B5  44
#define PIN_B6  45
#define PIN_B7  46
#define PIN_B8  47
#define PIN_B9  48
#define PIN_B10 49
#define PIN_B11 50

byte output_pins[] = {
  PIN_B1, //C0
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    PIN_B1,
    
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    PIN_B2,
    
    PIN_B3, //C1
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    PIN_B3,
    
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    PIN_B4,
    ///////
    PIN_B5, //C2
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    PIN_B5,
    
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    PIN_B6,
    
    PIN_B7, //C3
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    PIN_B7,
    
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    PIN_B8,
    
    PIN_B9, //C4
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    PIN_B9,
    
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    PIN_B10,
    
    PIN_B11, //C5
};
byte input_pins[] = {
PIN_A1, //C0
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1, //C1
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1, //C2
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1, //C3
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1, //C4
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,
    PIN_A8,
    PIN_A9,
    PIN_A10,
    PIN_A11,
    PIN_A12,
    PIN_A1, //C5
    PIN_A2
};

//cheap keyboards often has the black keys softer or harder than the white ones
//uncomment the next line to allow a soft correction
//#define BLACK_KEYS_CORRECTION

#ifdef BLACK_KEYS_CORRECTION
#define MULTIPLIER 192 // 127 is the central value (corresponding to 1.0)
byte black_keys[] = {
0,1,0,1,0,0,1,0,1,0,1,0,
0,1,0,1,0,0,1,0,1,0,1,0,
0,1,0,1,0,0,1,0,1,0,1,0,
0,1,0,1,0,0,1,0,1,0,1,0,
0,1,0,1,0,0,1,0,1,0,1,0,
0
};
#endif

//uncomment the next line to inspect the number of scans per seconds
//#define DEBUG_SCANS_PER_SECOND

/*
426 cyles per second (2,35ms per cycle) using standard digitalWrite/digitalRead
896 cyles per second (1,11ms per cycle) using DIO2 digitalWrite2/digitalRead2
*/

//uncoment the next line to get text midi message at output
//#define DEBUG_MIDI_MESSAGE

byte keys_state[KEYS_NUMBER];
unsigned long keys_time[KEYS_NUMBER];
boolean signals[KEYS_NUMBER * 2];
boolean pedal_enabled;
boolean is_sus;



void setup() {
  
Serial.begin(115200);
int i;
for (i = 0; i < KEYS_NUMBER; i++)
{
keys_state[i] = KEY_OFF;
keys_time[i] = 0;
}
for (byte pin = 0; pin < sizeof(output_pins); pin++)
{
pinMode(output_pins[pin], OUTPUT);
}
for (byte pin = 0; pin < sizeof(input_pins); pin++)
{
pinMode(input_pins[pin], INPUT_PULLUP);
}
pinMode(PEDAL_SUS, INPUT_PULLUP);
is_sus = false;
}



void send_midi_event(byte status_byte, byte key_index, unsigned long time)
{
unsigned long t = time;

#ifdef BLACK_KEYS_CORRECTION
if (black_keys[key_index])
{
t = (t * MULTIPLIER) >> 7;
}
#endif
if (t > MAX_TIME_MS)
t = MAX_TIME_MS;
if (t < MIN_TIME_MS)
t = MIN_TIME_MS;
t -= MIN_TIME_MS;

//unsigned long velocity = 127 - (t * 127 / MAX_TIME_MS_N);
//byte vel = (((velocity * velocity) >> 7) * velocity) >> 7;
byte vel = 127 - map(t, 0, MAX_TIME_MS_N, 0, 90);
//byte vel = 127 - map(t, MIN_TIME_MS, MAX_TIME_MS, 1, 90);
//Serial.println(vel);
// 0 ou tempo minimo?
byte key = 36 + key_index;
#ifdef DEBUG_MIDI_MESSAGE
char out[32];
sprintf(out, "%02X %02X %03d %d", status_byte, key, vel, t);
Serial.println(out);
#else
Serial.write(status_byte);
Serial.write(key);
Serial.write(vel);
#endif
}
void send_midi_eventcc(byte status_byte, byte key_index, unsigned long time)
{
unsigned long t = time;
#ifdef DEBUG_MIDI_MESSAGE
char out[32];
sprintf(out, "%02X %02X %03d %d", status_byte, key_index, vel, t);
Serial.println(out);
#else
Serial.write(status_byte);
Serial.write(key_index);
Serial.write(t);
#endif
}


void loop() {
//
potentiometers();

byte a = digitalRead(PEDAL_SUS);
//Serial.println(a);
if(a == 0){
      if(is_sus == true){
       send_midi_eventcc(0xB0, 64, 127);
       is_sus = false; 
      }
    }
    else{
      if(is_sus == false){
        send_midi_eventcc(0xB0, 64, 0);
        is_sus = true;
      }
    }
#ifdef DEBUG_SCANS_PER_SECOND
static unsigned long cycles = 0;
static unsigned long start = 0;
static unsigned long current = 0;
cycles++;
current = millis();
if (current - start >= 1000)
{
Serial.println(cycles);
cycles = 0;
start = current;
}
#endif

boolean *s = signals;
for (byte i = 0; i < KEYS_NUMBER * 2; i++)
{
    byte output_pin = output_pins[i];
    byte input_pin = input_pins[i];
    digitalWrite2(output_pin, LOW);
    *(s++) = !digitalRead2(input_pin);
    digitalWrite2(output_pin, HIGH);
}

byte          *state  = keys_state;
unsigned long *ktime  = keys_time;
boolean       *signal = signals;
for (byte key = 0; key < KEYS_NUMBER; key++)
{
    for (byte state_index = 0; state_index < 2; state_index++)
    {
        switch (*state)
        {
        case KEY_OFF:
            if (state_index == 0 && *signal)
            {
                *state = KEY_START;
                *ktime = micros();
            }
            break;
        case KEY_START:
            if (state_index == 0 && !*signal)
            {
                *state = KEY_OFF;
                break;
            }
            if (state_index == 1 && *signal)
            {
                *state = KEY_ON;
                unsigned long t= micros() - *ktime;
                send_midi_event(0x90, key,t);
            }
            break;
        case KEY_ON:
            if (state_index == 1 && !*signal)
            {
                *state = KEY_RELEASED;
                *ktime = micros();
            }
            break;
        case KEY_RELEASED:
            if (state_index == 0 && !*signal)
            {
                *state = KEY_OFF;
                unsigned long t= micros() - *ktime;
                send_midi_event(0x80, key,t);
            }
            break;
        }
        signal++;
    }
    state++;
    ktime++;
}
}