String message;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("darren");
  if(Serial.available()>=0){
    message="";
    Serial.println("ENTER MESSAGE:");
//    Serial.println(message);
//    message = Serial.readString();
//    Serial.println(message);
    while(message == ""){
      message = Serial.readString();
    }
    Serial.print("your message is:");
    Serial.println(message);
    
    delay(2000);
  }
}
