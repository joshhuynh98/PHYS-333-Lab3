// corresponds to 88 keys on piano, 0 for nothing
int period[] = {0,36364,34323,32396,30578,28862,27242,25713,24270,22908,21622,20408,19263,18182,17161,16198,15289,14431,13621,12856,12135,11454,10811,10204,9631,9091,8581,8099,7645,7215,6810,6428,6067,5727,5405,5102,4816,4545,4290,4050,3822,3608,3405,3214,3034,2863,2703,2551,2408,2273,2145,2025,1911,1804,1703,1607,1517,1432,1351,1276,1204,1136,1073,1012,956,902,851,804,758,716,676,638,602,568,536,506,478,451,426,402,379,358,338,319,301,284,268,253,239};

float pi = acos(-1.0);

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // middle C
  int note = 40;
  soundwave(3822, 261.6);
}

void pwm(float duration, float power, float ped, int pin) {
  /*
  duration (ms)
  power (out of 1000)
  period (microseconds)
  output pin
  */
  unsigned long time_0 = millis();

  while ((millis()-time_0) < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(power*ped);
    digitalWrite(pin, LOW);
    delayMicroseconds((1000-power)*ped);
  }
  return;
}

void soundwave(int ped, float freq) {
  unsigned long t = millis() % ped;
  float power = 500 * (sin(2*pi*t) +1);
  
  pwm(ped/1000,power,1,10);
}
