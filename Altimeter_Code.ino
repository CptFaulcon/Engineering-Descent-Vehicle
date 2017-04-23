#include <EYW.h>
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
  currentHeight=alt.getHeightAvg(25);
  Serial.println(currentHeight);
}
