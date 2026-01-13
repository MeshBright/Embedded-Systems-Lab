const int potPin = A0; 
int lastPotPin;
const int redLEDPin = 11;
const int yellowLEDPin = 10;
const int greenLEDPin = 9;
int redLEDValue;
int yellowLEDValue;
int greenLEDValue;
int brightness;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT); 
} 

void loop() 
{ 
  if (analogRead(potPin) <= 341)
  {
    for(int i = brightness; i > 0 ; --i)
    {
      if (lastPotPin >= 682 && lastPotPin <= 1024)
      {
        analogWrite(greenLEDPin, i);
      }
      else if (lastPotPin >=341 && lastPotPin <= 682)
      {
        analogWrite(yellowLEDPin, i);
      }
      
    }
  redLEDValue = analogRead(potPin);
  Serial.println(redLEDValue);
  brightness = map(redLEDValue, 0, 341, 0, 255); 
  analogWrite(redLEDPin, brightness); 
  analogWrite(yellowLEDPin, 0); 
  analogWrite(greenLEDPin, 0); 
    
  }
  
  else if (analogRead(potPin) <= 682)
  {

    for(int i = brightness; i > 0 ; --i)
    {
      if (lastPotPin >= 682 && lastPotPin <= 1024)
      {
        analogWrite(greenLEDPin, i);
      }
      else if (lastPotPin >= 0 && lastPotPin <= 341)
      {
        analogWrite(redLEDPin, i);
      }
    }

  yellowLEDValue = analogRead(potPin) - 341;
  Serial.println(yellowLEDValue);
  brightness = map(yellowLEDValue, 0, 341, 0, 255); 
  analogWrite(redLEDPin, 0);
  analogWrite(yellowLEDPin, brightness);
  analogWrite(greenLEDPin, 0); 
    
  }

  else if (analogRead(potPin) <= 1024)
  {

  for(int i = brightness; i > 0 ; --i)
    {
      if (lastPotPin >= 341 && lastPotPin <= 682)
      {
        analogWrite(yellowLEDPin, i);
      }
      else if (lastPotPin >= 0 && lastPotPin <= 341)
      {
        analogWrite(redLEDPin, i);
      }
    }
    
  greenLEDValue = analogRead(potPin) - 682;
  Serial.println(greenLEDValue);
  brightness = map(greenLEDValue, 0, 341, 0, 255); 
  analogWrite(redLEDPin, 0);
  analogWrite(yellowLEDPin, 0); 
  analogWrite(greenLEDPin, brightness);
    
  }

  lastPotPin = analogRead(potPin);

}