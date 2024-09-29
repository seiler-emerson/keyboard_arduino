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
        // CODIGO PARA modulation em A0 e pitchbend em A1
        //  if(i==0){// reservado para modulation wheel  
        //  send_midi_eventcc(0xB0, cc+ i, midiCState[i]);
        //  mod=false;
        //  }
        //  if(i==1){//reservado para pitchbend
        //  send_midi_eventcc(0xE0, cc+ i, midiCState[i]);
        //  pit=false;
        //  }
        //  if(i==2){ // reservado para controle de volume
          
        //  send_midi_eventcc(0xB0, 7, midiCState[i]); 
        //  }

      // Teste para Numero CC definido em config.h
        send_midi_eventcc(0xB0, cc+ MESSAGE_VAL[i], midiCState[i]); 

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