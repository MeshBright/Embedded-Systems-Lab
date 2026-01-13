// Include the required libraries
#include <SPI.h>       // Include the SPI protocol library
#include <MFRC522.h>   // Include the MFRC522 library

// Define the pins used for Reset and Slave Select
#define RST_PIN   9    // Configurable, can be any digital pin
#define SS_PIN    10   // Configurable, can be any digital pin

// Create an MFRC522 object
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);       // Initialize Serial Monitor
  while (!Serial);          // Wait for Serial Monitor to open
  SPI.begin();              // Initialize SPI bus
  mfrc522.PCD_Init();       // Initialize MFRC522 card reader
  
  Serial.println(F("RFID Reader Initialized."));
  Serial.println(F("Scan a card or fob..."));
}

void loop() {
  // Look for new cards
  // mfrc522.PICC_IsNewCardPresent() returns true if a card is detected
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return; // No card, exit the loop
  }

  // Select one of the cards
  // mfrc522.PICC_ReadCardSerial() returns true if the UID was read
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return; // Failed to read, exit the loop
  }

  // If we are here, a card was successfully read.
  Serial.print(F("Card UID: "));
  
  // Dump the UID to the Serial Monitor
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); // Print leading zero
    Serial.print(mfrc522.uid.uidByte[i], HEX); // Print the byte in hexadecimal
  }
  Serial.println();

  // Halt the tag to allow other tags to be read
  mfrc522.PICC_HaltA();
  
  // Wait 1 second before looking for another card
  delay(1000);
}