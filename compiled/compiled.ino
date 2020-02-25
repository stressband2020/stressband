//--------------temp
int val;
int tempPin = A4; //temp pin

//----------------BPM
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
const int PulseWirePin = A0;     //bpm pin  
const int bpmled = 3;          
int Threshold = 550;
PulseSensorPlayground pulseSensor;

//-------------GSR
const int GSR=A2; //gsr pin
int gsrValue=0;
int gsr_average=0;


void setup()
{
  Serial.begin(9600);
  pulseSensor.analogInput(PulseWirePin);   
  pulseSensor.blinkOnPulse(bpmled);    
  pulseSensor.setThreshold(Threshold);
}
void loop()
{
  //----------------temp  
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);

  //---------------bpm 
  int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {           
    Serial.print("BPM: ");                      
    Serial.println(myBPM);                   
  }
  delay(20);

  //----------------gsr
  long sum=0;
  for(int i=0;i<10;i++)
      {
      gsrValue=analogRead(GSR);
      sum += gsrValue;
      delay(5);
      }
   gsr_average = sum/10;
   Serial.println(gsr_average);
   Serial.println("{gsr:" + String(gsr_average) + ", bpm:" + String(myBPM) + ", temperature:" + String(cel) + "}");
}
