#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ArduinoJson.h>

#define SEALEVELPRESSURE_HPA (1013.25)
int incomingByte = 0;
Adafruit_BME280 bme; // I2C
DynamicJsonDocument doc(1024);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(9600);
  Serial.println(F("BME280 test"));

  bool status;
 
 
  status = bme.begin();  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
 
  Serial.println("-- Default Test --");


  Serial.println();
}


void donnees() {
  doc["Temperature"] = bme.readTemperature();
  doc["Pressure"] = bme.readPressure() / 100.0F;
  doc["Altitude"] = bme.readAltitude(SEALEVELPRESSURE_HPA);
  doc["Humidity"] = bme.readHumidity();
 

  Serial.println();
  serializeJson(doc, Serial);
  }

 // ledd  
void loop() {
  donnees();
  delay(3000);

 if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
 }
 if (incomingByte == '1'){
  digitalWrite(LED_BUILTIN, HIGH);   
 }
if (incomingByte == '0'){
    digitalWrite(LED_BUILTIN, LOW);   

}
}
void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}
