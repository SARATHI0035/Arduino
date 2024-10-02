// Required Components:
// 1. Touch Sensor Module - 1 unit (e.g., TTP223)
// 2. LED - 1 unit (for visual indication)
// 3. Buzzer - 1 unit (for sound indication)
// 4. Arduino Board (e.g., Arduino Uno) - 1 unit
// 5. Jumper Wires for connections
// 6. Resistor (220Ω for the LED)
// 7. Breadboard (optional for easier wiring)

// Initialize pins for touch sensor, LED, and buzzer
const int touch = 2;  // Touch sensor connected to pin 2
const int led = 6;    // LED connected to pin 6
const int buzz = 9;   // Buzzer connected to pin 9

void setup() {
  // Set the pin modes for the components
  pinMode(led, OUTPUT);  // Set LED pin as output
  pinMode(buzz, OUTPUT); // Set buzzer pin as output
  pinMode(touch, INPUT); // Set touch sensor pin as input
  Serial.begin(9600);    // Start serial communication at 9600 baud rate
}

void loop() {
  // Check if the touch sensor is touched
  // If the touch sensor is touched, it will send a HIGH signal
  if (digitalRead(touch) == HIGH) {
    digitalWrite(led, HIGH);    // Turn on the LED
    tone(buzz, 500);            // Activate the buzzer with a frequency of 500Hz
    Serial.println("Turn on");  // Print status to the serial monitor
    delay(2000);                // Wait for 2 seconds
  } 
  else {
    // If the touch sensor is not touched, turn off the LED and buzzer
    digitalWrite(led, LOW);     // Turn off the LED
    noTone(buzz);               // Deactivate the buzzer
    Serial.println("Turned off"); // Print status to the serial monitor
    delay(1000);                // Wait for 1 second
  }
}
