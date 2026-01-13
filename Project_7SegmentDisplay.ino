/* 7-Segment Display Counter (0-9)
  Display: 5161AS (Common Cathode)
  Logic: 1 = ON, 0 = OFF
*/

// Map the segments to your specific Arduino pins
// Order: {A, B, C, D, E, F, G, DP}
int segmentPins[] = {7, 6, 4, 3, 2, 8, 9, 5};

// Binary patterns for numbers 0-9
// The order here matches the order in segmentPins: A, B, C, D, E, F, G, DP
byte numbers[16][8] = {
  // A, B, C, D, E, F, G, DP
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9
  {1, 1, 1, 0, 1, 1, 1, 0}, // A
  {0, 0, 1, 1, 1, 1, 1, 0}, // B
  {1, 0, 0, 1, 1, 1, 0, 0}, // C
  {0, 1, 1, 1, 1, 0, 1, 0}, // D
  {1, 0, 0, 1, 1, 1, 1, 0}, // E
  {1, 0, 0, 0, 1, 1, 1, 0}  // F
};

void setup() {
  // Set all segment pins to OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Loop through numbers 0 to 9
  for (int num = 0; num < 16; num++) {
    
    // Write the pattern to the pins
    for (int i = 0; i < 8; i++) {
      digitalWrite(segmentPins[i], numbers[num][i]); 
    }
    
    delay(1000); // Wait 1 second
  }
}