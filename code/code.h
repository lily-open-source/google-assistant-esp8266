#include <Arduino.h>
#include <WiFi.h>
#include <GoogleAssistant.h>

// Replace these with your Wi-Fi credentials
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

// Replace this with the path to your JSON file with your GCP credentials
const char* credentials = "/path/to/credentials.json";

GoogleAssistant assistant(credentials);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }

  Serial.println("Connected to Wi-Fi");
  assistant.begin();
}

void loop() {
  assistant.loop();
}
