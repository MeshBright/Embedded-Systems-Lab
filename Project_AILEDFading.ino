const int potPin = A0; 
const int redLEDPin = 11;
const int yellowLEDPin = 10;
const int greenLEDPin = 9;

// We will read the sensor value ONCE into this variable
int potValue = 0;

// Variables to hold the brightness for each LED
int redBrightness = 0;
int yellowBrightness = 0;
int greenBrightness = 0;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT); 
} 

void loop() 
{ 
  // 1. Read the potentiometer value ONCE at the start of the loop
  potValue = analogRead(potPin);

  // 2. Do all the math to calculate brightness for ALL LEDs
  
  if (potValue < 341) // We are in the "Red" zone
  {
    // Red fades IN as pot goes from 0 to 341
    redBrightness = map(potValue, 0, 341, 0, 255);
    // Other LEDs are off
    yellowBrightness = 0;
    greenBrightness = 0;
  }
  else if (potValue < 682) // We are in the "Red-to-Yellow" zone
  {
    // Red fades OUT as pot goes from 341 to 682
    redBrightness = map(potValue, 341, 682, 255, 0);
    // Yellow fades IN as pot goes from 341 to 682
    yellowBrightness = map(potValue, 341, 682, 0, 255);
    // Green LED is off
    greenBrightness = 0;
  }
  else // We are in the "Yellow-to-Green" zone (682 to 1023)
  {
    // Red LED is off
    redBrightness = 0;
    // Yellow fades OUT as pot goes from 682 to 1023
    yellowBrightness = map(potValue, 682, 1023, 255, 0);
    // Green fades IN as pot goes from 682 to 1023
    greenBrightness = map(potValue, 682, 1023, 0, 255);
  }

  // 3. Write all the final brightness values to the LEDs
  analogWrite(redLEDPin, redBrightness);
  analogWrite(yellowLEDPin, yellowBrightness);
  analogWrite(greenLEDPin, greenBrightness);

  // 4. (Optional) Print the values for debugging
  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("\t R: ");
  Serial.print(redBrightness);
  Serial.print("\t Y: ");
  Serial.print(yellowBrightness);
  Serial.print("\t G: ");
  Serial.println(greenBrightness);
  
  delay(10); // A small delay to keep the Serial Monitor readable
}