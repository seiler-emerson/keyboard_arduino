#include <DIO2.h>          // Biblioteca DIO2 para I/O rápido
#include "config.h"        // Definições de pinos e variáveis globais
#include "input.h"         // Leitura das entradas do teclado e pedal
#include "midi.h"          // Função para enviar eventos MIDI
#include "states.h"        // Funções para gerenciar os estados das teclas

void setup() {
    Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);

    iniciarConfiguracoes();
}

void loop() {
    #ifdef DEBUG_SCANS_PER_SECOND
    contarCiclos();          // Função para contar ciclos por segundo (debug)
    #endif
    
    lerEntradas();           // Lê o estado das teclas e do pedal
    atualizarEstados();      // Atualiza os estados das teclas e envia MIDI
}
