//Left BTS7960 pins
int R_EN1 = 3;
int L_EN1 = 4;
int R_PWM1 = 5;
int L_PWM1 = 6;

//Right BTS7960 pins
int R_EN2 = 7;
int L_EN2 = 8;
int R_PWM2 = 9;
int L_PWM2 = 10;

//data holds value received via bluetooth
char data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(R_EN1, OUTPUT);
  pinMode(L_EN1, OUTPUT);
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
   
  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    data=Serial.read();
    if (data=='F') {
     analogWrite(R_PWM1, 0);
     analogWrite(L_PWM1, 255);
     analogWrite(R_PWM2, 255);
     analogWrite(L_PWM2, 0);
    }
    if (data=='B') {
     analogWrite(R_PWM1, 255);
     analogWrite(L_PWM1, 0);
     analogWrite(R_PWM2, 0);
     analogWrite(L_PWM2, 255);
    }
    if (data=='L') {
     analogWrite(R_PWM1, 0);
     analogWrite(L_PWM1, 200);
     analogWrite(R_PWM2, 0);
     analogWrite(L_PWM2, 200);
    }
    if (data=='R') {
     analogWrite(R_PWM1, 200);
     analogWrite(L_PWM1, 0);
     analogWrite(R_PWM2, 200);
     analogWrite(L_PWM2, 0);
    }
    if (data=='G') { //Right 45
     analogWrite(R_PWM1, 0);
     analogWrite(L_PWM1, 255);
     analogWrite(R_PWM2, 100);
     analogWrite(L_PWM2, 0);
    }
    if (data=='I') {
     analogWrite(R_PWM1, 0);
     analogWrite(L_PWM1, 100);
     analogWrite(R_PWM2, 255);
     analogWrite(L_PWM2, 0);
    }
    if (data=='S') {
     analogWrite(R_PWM1, 0);
     analogWrite(L_PWM1, 0);
     analogWrite(R_PWM2, 0);
     analogWrite(L_PWM2, 0);
    }  
  }
}
