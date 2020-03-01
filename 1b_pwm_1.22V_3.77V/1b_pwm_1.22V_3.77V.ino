
void setup() {

  pinMode(10, OUTPUT);
}

void loop() {

  //analogWrite(10, (1.22/5)*256-1);
  //delay(100);
  pwm(100,244,2,10);

  //analogWrite(10, (3.77/5)*256-1);
  //delay(200);
  pwm(200,754,2,10);
}

void pwm(float duration, float power, float period, int pin) {
  /*
  duration (ms)
  power (out of 1000)
  period (microseconds)
  output pin
  */
  unsigned long time_0 = micros();

  while ((micros()-time_0) < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(power*period);
    digitalWrite(pin, LOW);
    delayMicroseconds((1000-power)*period);
  }
  return;
}
