#include <Servo.h>

#define btne1 5
#define btnd1 6
#define btne2 7
#define btnd2 8

unsigned long tempo_btne1 = 0;
unsigned long tempo_btnd1 = 0;
unsigned long tempo_btne2 = 0;
unsigned long tempo_btnd2 = 0;

int j1 = 90;
int j2 = 90;

Servo servo_junta1;
Servo servo_junta2;  

void setup() {
  pinMode(btne1, INPUT_PULLUP);
  pinMode(btnd1, INPUT_PULLUP);
  pinMode(btne2, INPUT_PULLUP);
  pinMode(btnd2, INPUT_PULLUP);
    
  servo_junta1.attach(3);
  servo_junta2.attach(4);

  servo_junta1.write(j1);
  servo_junta2.write(j2);
}

void loop() {
  if ((millis() - tempo_btne1 >= 15) && (digitalRead(btne1) == LOW)) {
    if (j1 > 0) {
      j1--;
    }
    servo_junta1.write(j1);
    tempo_btne1 = millis();
  }

  if ((millis() - tempo_btnd1 >= 15) && (digitalRead(btnd1) == LOW)) {
    if (j1 < 180) {
      j1++;
    }
    servo_junta1.write(j1);
    tempo_btnd1 = millis();
  }

  ////////

  if ((millis() - tempo_btne2 >= 15) && (digitalRead(btne2) == LOW)) {
    if (j2 > 0) {
      j2--;
    }
    servo_junta2.write(j2);
    tempo_btne2 = millis();
  }

  if ((millis() - tempo_btnd2 >= 15) && (digitalRead(btnd2) == LOW)) {
    if (j2 < 180) {
      j2++;
    }
    servo_junta2.write(j2);
    tempo_btnd2 = millis();
  }
}
