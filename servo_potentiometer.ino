#include <Servo.h>
Servo myservo;
void setup()
{
  myservo.attach(9);
}

void loop()
{
 //take input from potentiometer
 int servospeed=analogRead(A0);
  servospeed=map(servospeed,0,1023,0,180);
 //give output signal to servo from pin 9
 myservo.write(servospeed);
 delay(100);
}
