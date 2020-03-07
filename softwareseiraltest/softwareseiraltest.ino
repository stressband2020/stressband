
#include <SoftwareSerial.h>
SoftwareSerial myserial(3, 2); // RX, TX
String data="";

int c=0;
void setup() {
  // put your setup code here, to run once:
  myserial.begin(9600);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = "{'bpm':"+String(c)+"}";
  Serial.println(data);
  myserial.print(data);
  c++;
  delay(3000);
}
