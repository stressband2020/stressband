unsigned long time;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("Time: ");
  time = millis()+10000;

  while(millis()<(time)){
    Serial.print(millis());
    Serial.print("--");
    Serial.println(time);
  }
  
  Serial.println("*************");
  delay(3000);
}
