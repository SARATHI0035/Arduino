// Required Components:
// 1. PIR Motion Sensor - 1 unit (to detect motion)
// 2. Buzzer - 1 unit (to provide sound alert when motion is detected)
// 3. LED - 1 unit (to provide visual alert when motion is detected)
// 4. Arduino Board (e.g., Arduino Uno) - 1 unit
// 5. Jumper Wires for connections
// 6. Breadboard (optional for easier wiring)
// 7. Power Supply (from Arduino or external for buzzer and LED)

const int buzzer = 6;  // Initialize buzzer pin
const int led = 5;     // Initialize LED pin
const int pir = 7;     // Initialize PIR sensor pin

void setup() {
  // Setup the connected digital pins
  pinMode(buzzer, OUTPUT);  // Set buzzer as output
  pinMode(led, OUTPUT);     // Set LED as output
  pinMode(pir, INPUT);      // Set PIR sensor as input

  Serial.begin(9600);       // Begin serial communication at 9600 baud rate
}

void loop() {
  // If motion is detected (PIR sensor goes HIGH), turn on LED and buzzer
  if (digitalRead(pir) == HIGH) {
    digitalWrite(buzzer, HIGH);  // Turn on the buzzer
    digitalWrite(led, HIGH);     // Turn on the LED
    delay(2000);                 // Wait for 2 seconds
    Serial.println("Motion detected");  // Print message to the serial monitor
  } 
  else {
    // If no motion is detected, turn off LED and buzzer
    digitalWrite(buzzer, LOW);   // Turn off the buzzer
    digitalWrite(led, LOW);      // Turn off the LED
    delay(1000);                 // Wait for 1 second
    Serial.println("Motion not detected");  // Print message to the serial monitor
  }
}
