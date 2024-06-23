int trigPin = 3;
const int echoPin = 2;
const int buzzer = 11;
const int led = 12;

//deinfes variables
long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT); //Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  //Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); //Starts serial communication at 9600 baud rate
}
void loop() {

  //Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Sets the trigPin to HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Reads the echoPin and returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  //Calculates distance
  distance = duration*0.034/2;

  if(distance < 10) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    tone(buzzer, 500);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
  
  //Displays distance on Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print(" cm");
  delay(500);
}
