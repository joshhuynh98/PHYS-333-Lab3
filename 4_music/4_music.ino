// corresponds to 88 keys on piano, 0 for nothing
int period[] = {0,36364,34323,32396,30578,28862,27242,25713,24270,22908,21622,20408,19263,18182,17161,16198,15289,14431,13621,12856,12135,11454,10811,10204,9631,9091,8581,8099,7645,7215,6810,6428,6067,5727,5405,5102,4816,4545,4290,4050,3822,3608,3405,3214,3034,2863,2703,2551,2408,2273,2145,2025,1911,1804,1703,1607,1517,1432,1351,1276,1204,1136,1073,1012,956,902,851,804,758,716,676,638,602,568,536,506,478,451,426,402,379,358,338,319,301,284,268,253,239};

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 115 bpm
  int ms_per_16th = 30;
  
  //87 notes opening
  int notes[] = {20, 20, 32,
                 20, 20, 30,
                 20, 20, 28,
                 20, 20, 26,
                 20, 20, 27, 28,
                 20, 20, 32,
                 20, 20, 30,
                 20, 20, 28,
                 20, 20, 26, 0,
                 20, 20, 32,
                 20, 20, 30,
                 20, 20, 28,
                 20, 20, 26,
                 20, 20, 27, 28,
                 20, 20, 32,
                 20, 20, 30,
                 20, 20, 28,
                 20, 20, 26, 0,
                 20, 20, 32,
                 20, 20, 30,
                 20, 20, 28,
                 20, 20, 26,
                 20, 20, 27, 28,
                 20, 20, 32,
                 20, 20, 30,
                 20, 20, 28,
                 20, 20, 26
                };
  int duration[] = {4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 3, 3,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 10, 6,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 3, 3,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 10, 6,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 3, 3,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 4,
                    4, 4, 10
                   };
  // 12 notes bridge
  int bridge[] = {36, 32, 28,
                  51, 35, 28,
                  32, 35, 51,
                  35, 32, 28};
  int bduration[] = {2, 2, 2,
                     2, 2, 2,
                     2, 2, 2,
                     2, 2, 2};
                   
  for (int i=0; i<86; i++) {
    delay(35);
    play(ms_per_16th*duration[i],notes[i],10);
  }
  for (int i=0; i<12; i++) {
    play(ms_per_16th*bduration[i],bridge[i],10);
    delay(15);
  }
  for (int i=0; i<86; i++) {
    delay(25);
    play(ms_per_16th*duration[i],notes[i],10);
  }

  delay(2000);
}

void play(int dur_ms, int note, int pin) {

  unsigned int t0;
  t0 = millis();
  if (note>0) {
    while ((millis()-t0) < dur_ms) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(period[note]/2);
      digitalWrite(pin, LOW);
      delayMicroseconds(period[note]/2);
    }
  }
  else {
    digitalWrite(pin, LOW);
    delay(dur_ms);  
  }

  return;
}
