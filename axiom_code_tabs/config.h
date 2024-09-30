// ========= TECLAS =========
#define KEYS_NUMBER 61
#define KEY_OFF 0
#define KEY_START 1
#define KEY_ON 2
#define KEY_RELEASED 3
#define KEY_SUSTAINED 4
#define KEY_SUSTAINED_RESTART 5

// ========= SENSIBILIDADE TECLAS =========
#define MIN_TIME_MS 3
#define MAX_TIME_MS 150
#define MAX_TIME_MS_N (MAX_TIME_MS - MIN_TIME_MS)

// DEFINIÇÃO PINO PEDAL
#define PEDAL_PIN 21

// DEFINIÇÃO PINOS MATRIZ DO TECLADO
#define PIN_A1 22
#define PIN_A2 24
#define PIN_A3 26
#define PIN_A4 28
#define PIN_A5 30
#define PIN_A6 32
#define PIN_A7 34
#define PIN_A8 36
#define PIN_A9 38
#define PIN_A10 40
#define PIN_A11 42
#define PIN_A12 44

#define PIN_B1 23
#define PIN_B2 25
#define PIN_B3 27
#define PIN_B4 29
#define PIN_B5 31
#define PIN_B6 33
#define PIN_B7 35
#define PIN_B8 37
#define PIN_B9 39
#define PIN_B10 41
#define PIN_B11 43

byte output_pins[] = {
  PIN_B1,  //C0
  PIN_B1,  //C0
  PIN_B1,  //C#0
  PIN_B1,  //C#0
  PIN_B1,  // D0
  PIN_B1,  // D0
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

  PIN_B3,  //C1
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
  PIN_B5,  //C2
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

  PIN_B7,  //C3
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

  PIN_B9,  //C4
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

  PIN_B11,  //C5
};
byte input_pins[] = {
  PIN_A1,  //C0
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
  PIN_A1,  //C1
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
  PIN_A1,  //C2
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
  PIN_A1,  //C3
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
  PIN_A1,  //C4
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
  PIN_A1,  //C5
  PIN_A2
};

// Variáveis globais
byte keys_state[KEYS_NUMBER];
unsigned long keys_time[KEYS_NUMBER];
boolean signals[KEYS_NUMBER * 2];
boolean pedal_enabled;
byte pedal = LOW;

// ========= POTENCIOMETROS =========
const int N_POTS = 3; //* número total de pots (slide e rotativo)
const int POT_ARDUINO_PIN[N_POTS] = {A0, A1, A2}; //* pinos de cada pot conectado diretamente ao Arduino (AO = modulation wheel  | A1 = pitchbend)
byte MESSAGE_VAL[N_POTS] = { 0, 1, 7 }; //* Número CC que você deseja enviar, na ordem correspondente aos potenciometros acima

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

// ========= DEBUG =========
//#define DEBUG_SCANS_PER_SECOND

void startConfig() {
  // Serial.begin(115200); // 115200 for hairless - 31250 for MOCO lufa  pinMode(13, OUTPUT);
  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  int i;
  for (i = 0; i < KEYS_NUMBER; i++) {
    keys_state[i] = KEY_OFF;
    keys_time[i] = 0;
  }
  for (byte pin = 0; pin < sizeof(output_pins); pin++) {
    pinMode(output_pins[pin], OUTPUT);
  }
  for (byte pin = 0; pin < sizeof(input_pins); pin++) {
    pinMode(input_pins[pin], INPUT_PULLUP);
  }
  pinMode(PEDAL_PIN, INPUT_PULLUP);
  pedal_enabled = digitalRead(PEDAL_PIN) != HIGH;
}
