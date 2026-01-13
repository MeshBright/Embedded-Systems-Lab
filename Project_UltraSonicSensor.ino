#include <NewPing.h>

// 1. Configuration
const int echoPin = 10;
const int trigPin = 9;
const int greenLEDPin = 8;
const int yellowLEDPin = 7;
const int redLEDPin = 6;
const int activeBuzzerPin = 5;

#define MAX_DISTANCE 200 

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

void setup() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(activeBuzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(50); 
  unsigned int uS = sonar.ping_median(5); 
  
  // Convert that time to distance (cm)
  int distance = sonar.convert_cm(uS);

  // Fix for 0 reading
  if (distance == 0) distance = MAX_DISTANCE;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // --- LOGIC TREE ---
  
  if (distance > 15) {
    // SAFE
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(activeBuzzerPin, LOW); // Silence
    
  } else if (distance < 15 && distance > 8) {
    // CAUTION
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(activeBuzzerPin, LOW); // Silence

  } else {
    // DANGER - WARNING ALARM
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    
    // Blink Red LED
    digitalWrite(redLEDPin, HIGH);
    
    // MAKE SOUND (The Fix)
    // We call our custom function instead of tone()
    alarmSound(100); 
    
    digitalWrite(redLEDPin, LOW);
    delay(100); 
    
    Serial.println("WARNING: TOO CLOSE!");
  }
}

// --- CUSTOM FUNCTION TO REPLACE TONE() ---
// This makes sound without using the "Timer 2" hardware
// so it doesn't crash the NewPing library.
void alarmSound(int duration_ms) {
  // If you have a TRUE Active Buzzer (has a sticker on top), 
  // you only need this line:
  digitalWrite(activeBuzzerPin, HIGH); 
  delay(duration_ms); 
  digitalWrite(activeBuzzerPin, LOW);

}