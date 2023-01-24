#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Define the pins that we will use
#define SENSOR 33
#define LED 26


DHT dht(33, DHT11);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

   dht.begin();
   Serial.begin(9600);
}

void loop() {
 
   float h = dht.readHumidity();
   float t = dht.readTemperature();
  // Effectuer une mesure toutes les 5s

  // Afficher l'humidité relative avec un peu de formatage
   Serial.print("Humidity: ");
   Serial.println(h);
  // Afficher la température avec un peu de formatage
   Serial.print("Temperature: ");
   Serial.println(t);
}