const int activeBuzzerPin = 11; 
const int passiveBuzzerPin = 12;
void setup() 
{ 
  pinMode(activeBuzzerPin, OUTPUT);
  pinMode(passiveBuzzerPin, OUTPUT); 
} 

void loop() 
{ 
  // for the passive buzzer
  digitalWrite(activeBuzzerPin, HIGH);
  digitalWrite(activeBuzzerPin, LOW);

  // for the active buzzer
  tone(passiveBuzzerPin, 2000, 1000);
  delay(1100); 
}