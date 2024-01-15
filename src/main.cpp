/*
MIT License

Copyright (c) 2024 iAchieved.it LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEBeacon.h>

#define SWITCH_PIN 21
#define LED_PIN 14

// https://support.kontakt.io/hc/en-gb/articles/4413251561106-iBeacon-packets

#define BEACON_UUID     "bf707dd7-a3c3-4a4b-b98b-88c175b7d730"

void hexdump(std::string data) {
  for (int i = 0; i < data.length(); i++) {
    Serial.printf("%02x ", data[i]);
  }
  Serial.println();
}

BLEAdvertising* pAdvertising;

void setup() {
  Serial.begin(115200);
  BLEDevice::init("ESP32");

  BLEBeacon beacon;
  BLEUUID bleUUID = BLEUUID(BEACON_UUID); 
  bleUUID = bleUUID.to128();
  beacon.setProximityUUID(BLEUUID( bleUUID.getNative()->uuid.uuid128, 16, true ));
  beacon.setManufacturerId(0x4c00); // Apple
  beacon.setMajor(0);
  beacon.setMinor(0);
  beacon.setSignalPower(0xc8);

  BLEAdvertisementData advertisementData;
  advertisementData.setFlags(0x06);
  advertisementData.setManufacturerData(beacon.getData());

  Serial.println("iBeacon payload:  ");
  hexdump(advertisementData.getPayload());
  
  pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->setAdvertisementData(advertisementData);

  pinMode(SWITCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);


}

void loop() {

  static bool advertising = false;

  int button = digitalRead(SWITCH_PIN);

  if (button) {
    if (advertising) {
      advertising = false;
      pAdvertising->stop();
      Serial.println("Advertising stopped...it may take up to 45 seconds for devices to exit");

      digitalWrite(LED_PIN, LOW);
    } else {
      advertising = true;
      pAdvertising->start();
      Serial.println("Advertising started...");
      digitalWrite(LED_PIN, HIGH);
    }
  }

  delay(250);
  
}