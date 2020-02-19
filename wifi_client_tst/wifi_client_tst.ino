

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "stress_band";
const char* password = "abcdABCD1234*";

int i=0;
void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(i);
    Serial.print(":");
    Serial.println(password);
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED){
    Serial.println("CONNECTED");
    HTTPClient http;
    http.begin("http://35.187.248.66:8080/api/test");
    http.addHeader("Content-Type", "text/plain");
    
    int httpCode = http.POST("HELLO FROM ARDUINO");
    String payload = http.getString();

    Serial.print(httpCode);
    Serial.print(":");
    Serial.println(payload);
    
  }
  else{
     Serial.print("NOT CONNECTED:");
     Serial.println(WiFi.localIP());
    }
}
