#include <Servo.h>

// Required Components:
// 1. Servo Motor (e.g., SG90 or MG996R) - 1 unit
// 2. IR Sensors - 2 units (for object detection or line tracking)
// 3. Arduino Board (e.g., Arduino Uno) - 1 unit
// 4. Jumper Wires for connections
// 5. Breadboard (optional for easier wiring)
// 6. Power Supply (5V from Arduino or external for the servo)

// Create a Servo object
Servo motor; 

// Define pins for IR sensors
int ir1 = 4;  // IR sensor 1 connected to pin 4
int ir2 = 5;  // IR sensor 2 connected to pin 5

void setup() {
  // Attach the servo motor to pin 9
  motor.attach(9);

  // Set IR sensor pins as inputs
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);

  // Set servo to initial position (0 degrees)
  motor.write(0);
  delay(1000);  // Wait for 1 second
}

void loop() {
  // Read signals from the IR sensors
  // LOW means the sensor detects an object
