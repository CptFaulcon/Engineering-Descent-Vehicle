#include <EYW.h>
#include <Servo.h>
#include <Wire.h>
EYW::Altimeter alt; 
float currentHeight;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  alt.begin();
  alt.calibrate(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!moving()){
    
  }
  while(!reachedGround()){
    
  }
  while(true){
    tone(5, 261.6, 100);
    noTone(100);
  }
  
}
boolean reachedGround(){
  int dataPoints = 4;
  float sum;
  float  heights[4]={};
  for(int i = 0; i<=dataPoints;i++){
    heights[i]=alt.getHeightAvg(20);
  }
  for(int i = 0;i<dataPoints-1;i++){
    sum+=heights[i+1]-heights[i];
  }
  if(sum/dataPoints>0.3)
    return true;
  return false;
  
}
boolean moving(){
  int dataPoints = 4;
  float sum;
  float  heights[4]={};
  for(int i = 0; i<=dataPoints;i++){
    heights[i]=alt.getHeightAvg(20);
  }
  for(int i = 0;i<dataPoints-1;i++){
    sum+=heights[i+1]-heights[i];
  }
  if(sum/dataPoints>0.3)
    return false;
  return true;
}

