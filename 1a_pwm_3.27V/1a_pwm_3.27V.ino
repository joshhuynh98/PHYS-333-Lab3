void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(10,(3.27/5)*256-1);

  // break into 500 intervals -> 2 ms period
  pwm(1000,654,2,10);
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
