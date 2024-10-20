
#define BLYNK_TEMPLATE_ID "TMPL3FwFZ5UR6"
#define BLYNK_TEMPLATE_NAME "LED ON OFF"
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>

//Define the relay/LED pins using GPIO numbers for ESP32 DevKit V1
#define light1 22  // GPIO for light 1
#define light2 5  // GPIO for light 2
#define light3 15  // GPIO for light 3 (new LED)
#define wifiLed 2  // GPIO for the built-in LED on ESP32

// Blynk authentication token
#define BLYNK_AUTH_TOKEN ""  // Enter your Blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";  // Enter your WiFi SSID
char pass[] = "";  // Enter your WiFi password

// Get the button values from Blynk app for Light 1
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  // Check the values and turn relay1 ON/OFF
  if (value1 == 1) {
    digitalWrite(light1, LOW);  // Turn ON (assuming relay LOW is active)
  } else {
    digitalWrite(light1, HIGH);  // Turn OFF
  }
}

// Get the button values from Blynk app for Light 2
BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  // Check the values and turn relay2 ON/OFF
  if (value2 == 1) {
    digitalWrite(light2, LOW);  // Turn ON
  } else {
    digitalWrite(light2, HIGH);  // Turn OFF
  }
}

// Get the button values from Blynk app for Light 3 (new LED)
BLYNK_WRITE(V2) {
  bool value3 = param.asInt();
  // Check the values and turn relay3 ON/OFF
  if (value3 == 1) {
    digitalWrite(light3, LOW);  // Turn ON
  } else {
    digitalWrite(light3, HIGH);  // Turn OFF
  }
}

void setup() {
  Serial.begin(9600);  // Start serial communication
  delay(100);

  // Set the relay/LED pins as output
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);  // Set the third LED as output
  pinMode(wifiLed, OUTPUT);

  // Turn OFF the relays/LEDs initially
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  digitalWrite(light3, HIGH);  // Turn OFF the third LED initially
  digitalWrite(wifiLed, HIGH);

  // Initialize the Blynk connection
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  // Keep Blynk connected and running
  Blynk.run();
}
