#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h> 
#include <DHT_U.h>

// Define the pins that we will use
#define SENSOR 33
#define LED 26


DHT_Unified dht(SENSOR, DHT11);



void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  // Initialize device.
  dht.begin();
  sensors_event_t event;
  dht.temperature().getEvent(&event);
   if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
  Serial.print("Going to sleep.");
  delay(100);
  esp_sleep_enable_timer_wakeup(5000000);
  esp_deep_sleep_start();
}

void loop(){}

