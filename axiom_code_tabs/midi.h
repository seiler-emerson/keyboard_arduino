void send_midi_event(byte status_byte, byte key_index, unsigned long time) {
  unsigned long t = time;
#ifdef BLACK_KEYS_CORRECTION
  if (black_keys[key_index]) {
    t = (t * MULTIPLIER) >> 7;
  }
#endif
  if (t > MAX_TIME_MS)
    t = MAX_TIME_MS;
  if (t < MIN_TIME_MS)
    t = MIN_TIME_MS;
  t -= MIN_TIME_MS;
  unsigned long velocity = 127 - (t * 127 / MAX_TIME_MS_N);
  byte vel = (((velocity * velocity) >> 7) * velocity) >> 7;
  byte key = 36 + key_index;
#ifdef DEBUG_MIDI_MESSAGE
  char out[32];
  sprintf(out, "%02X %02X %03d %d", status_byte, key, vel, time);
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
