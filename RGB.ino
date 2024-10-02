// Required Components:
// 1. RGB LED (or separate Red, Green, and Blue LEDs)
// 2. Resistors (220Ω for each LED to limit current)
// 3. Arduino Board (e.g., Arduino Uno) - 1 unit
// 4. Jumper Wires for connections
// 5. Breadboard (optional for easier wiring)

// Initialize pins for Red, Green, and Blue LED
const int red = 2;
const int green = 3;
const int blue = 4;

void setup() {
  // Set the RGB pins as OUTPUT
  pinMode(red, OUTPUT);    // Red LED pin
  pinMode(green, OUTPUT);  // Green LED pin
  pinMode(blue, OUTPUT);   // Blue LED pin
}

void loop() {
  // Blink Red LED
  digitalWrite(red, HIGH);   // Turn on Red LED
  delay(100);                // Wait for 100 ms
  digitalWrite(red, LOW);    // Turn off Red LED
  delay(100);                // Wait for 100 ms
  
  // Blink Green LED
  digitalWrite(green, HIGH); // Turn on Green LED
  delay(100);                // Wait for 100 ms
  digitalWrite(green, LOW);  // Turn off Green LED
  delay(100);                // Wait for 100 ms

  // Blink Blue LED
  digitalWrite(blue, HIGH);  // Turn on Blue LED
  delay(100);                // Wait for 100 ms
  digitalWrite(blue, LOW);   // Turn off Blue LED
  delay(100);                // Wait for 100 ms
}
