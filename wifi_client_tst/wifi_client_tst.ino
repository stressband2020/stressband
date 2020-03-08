 #include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "stress_band";
const char* password = "abcdABCD1234*";
String data;
// Change the ip depending on the ip of listening api

String ip = "34.87.167.59";
String port = "8080";
String URL = "http://"+ip+":"+port+"/api/test";

int connection_led = 2;

int i=0;
void setup() {
  Serial.begin(9600);

  // We start by connecting to a WiFi network
  pinMode(connection_led, OUTPUT);
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
  if(WiFi.status() == WL_CONNECTED) {
    digitalWrite(connection_led, LOW);
    if(Serial.available()>=0){
      data = Serial.readString();
      if(data != ""){
        post_request();
        data = "";
      }
    }
  }
  else{
    Serial.println("NOT CONNECTED");
    digitalWrite(connection_led, HIGH);
  }
}

void post_request(){
  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "text/plain");

  int httpCode = http.POST(data);
  String payload = http.getString();

  Serial.print(httpCode);
  Serial.print(":");
  Serial.println(payload);

}
