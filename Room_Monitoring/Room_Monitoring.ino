#include <Wire.h>
#include "DHT20.h"
#include <WiFi.h>

DHT20 DHT(&Wire);  // Standard I2C interface

const char* ssid = ""; // Dein WLAN-SSID
const char* password = ""; // Dein WLAN-Passwort

void setup() {
  Serial.begin(115200);
  
  Wire.begin(21, 22);  // SDA auf Pin 21, SCL auf Pin 22
  
  // WLAN verbinden
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi verbunden.");
}

void loop() {
  float humidity = DHT.getHumidity();
  float temperature = DHT.getTemperature();
  Serial.print("H: ");
  Serial.print(humidity, 1);
  Serial.print("%,\t T: ");
  Serial.println(temperature, 1);

  delay(2000);
}