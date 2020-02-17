//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseRoom_ESP8266 is a sample that demo using multiple sensors
// and actuactor with the FirebaseArduino library.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "stressband-bed7e.firebaseio.com"
#define FIREBASE_AUTH "DEjUdkXNlbkYfb3ApMYOawOKbsri93sFoUk3niZh"
#define WIFI_SSID "TRINIDAD 2.4"
#define WIFI_PASSWORD "abcdABCD1234*"



void setup() {
  Serial.begin(9600);



  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if(Firebase.failed()){
    Serial.println("error connecting to firevase");
  }
  Firebase.pushInt("BPM", 42);
   if(Firebase.failed()){
    Serial.print("error");
    Serial.println(Firebase.error());
  }
  
}

int button = 0;
float light = 0.0;

void loop() {
  int button = 0;
}
