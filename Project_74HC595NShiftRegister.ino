int latchPin = 12;
int clockPin = 13;
int dataPin = 11;

// 1. THE SHADOW VARIABLE
// This byte holds the current status of all your LEDs. 
// Initially 0 (all OFF).

// Hex codes for digits 0-9 and A-F
byte seven_seg_digits[16] = { 
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F, // 9
  0x77, // A
  0x7C, // B
  0x39, // C
  0x5E, // D
  0x79, // E
  0x71  // F
};


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(latchPin, LOW);
    
    // Look how simple this line becomes!
    // We just grab the hex code from the box:
    shiftOut(dataPin, clockPin, MSBFIRST, seven_seg_digits[i]);  
    
    digitalWrite(latchPin, HIGH);
    delay(1000); 
  }
}


