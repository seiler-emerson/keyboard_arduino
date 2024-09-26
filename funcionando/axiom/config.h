// Definições de pinos e constantes globais

#define KEYS_NUMBER 61
#define KEY_OFF 0
#define KEY_START 1
#define KEY_ON 2
#define KEY_RELEASED 3
#define KEY_SUSTAINED 4
#define KEY_SUSTAINED_RESTART 5

#define MIN_TIME_MS 3
#define MAX_TIME_MS 150
#define MAX_TIME_MS_N (MAX_TIME_MS - MIN_TIME_MS)

#define PEDAL_PIN 21

#define PIN_A1 22
#define PIN_A2 23
#define PIN_A3 24
#define PIN_A4 25
#define PIN_A5 26
#define PIN_A6 27
#define PIN_A7 28
#define PIN_A8 29
#define PIN_A9 30
#define PIN_A10 31
#define PIN_A11 32
#define PIN_A12 33

#define PIN_B1 34
#define PIN_B2 35
#define PIN_B3 36
#define PIN_B4 37
#define PIN_B5 38
#define PIN_B6 39
#define PIN_B7 40
#define PIN_B8 41
#define PIN_B9 42
#define PIN_B10 43
#define PIN_B11 44

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

void iniciarConfiguracoes() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
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
