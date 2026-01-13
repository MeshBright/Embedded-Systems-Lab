int LEDPin = 8;
int buttonPin = 12;
int buttonRead;
int isPressed = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LEDPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonRead = digitalRead(buttonPin);
Serial.println(buttonRead);
delay(250);

if (buttonRead == 1)
{
  digitalWrite(LEDPin, LOW);
}
else
{
  digitalWrite(LEDPin, HIGH);
}
}
