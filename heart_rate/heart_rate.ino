int val;
int tempPin = 1;
int bpm = 0;
unsigned long time;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bpm = 0;
  time = millis()+10000;
  while(millis()<time){
    val = analogRead(tempPin);
    Serial.print("**");
    Serial.print(val);
    Serial.println("**");
    if (val > 400 && val < 550){
      Serial.println(val);
      bpm++;
    }
    delay(100);
  }
  Serial.print("BPM:");
  Serial.println(bpm*6);
  delay(5000);

}
