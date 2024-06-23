#define LED 13
char data;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);   
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    data=Serial.read();
    if (data=='1') {
      digitalWrite(LED,HIGH);
    }
    else if (data=='0') {
      digitalWrite(LED,LOW);
    }
  }
}
