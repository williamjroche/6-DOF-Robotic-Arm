#include <Servo.h>

Servo base, shoulder, elbow, wristPitch, wristRoll, gripper;

void setup() {
  base.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wristPitch.attach(9);
  wristRoll.attach(10);
  gripper.attach(12);


//home position
  home();
}

void loop() {
  home();
  //move to position 1
  base.write(85);
  delay(500);
  for(int i = 90; i <= 122; i++){
    shoulder.write(i);
    delay(10);
  }
  delay(500);
  gripper.write(120);
  delay(500);
  for(int i = 90; i >= 20; i--){
    elbow.write(i);
    delay(10);
  }
  delay(500);
  for(int i = 90; i >= 50; i--){
    wristPitch.write(i);
    delay(10);
  }
  delay(500);
  gripper.write(0);
  delay(500);
  
  home();

  delay(500);
  //move to position 2
  for(int i = 90; i<=125; i++){
    base.write(i);
    delay(10);
  }
  delay(500);
  for(int i = 90; i <= 122 ; i++){
    shoulder.write(i);
    delay(10);
  }
  delay(500);
  gripper.write(0);
  delay(500);
  for(int i = 90; i >= 35; i--){
    elbow.write(i);
    delay(10);
  }
  delay(500);
  for(int i = 90; i >= 50; i--){
    wristPitch.write(i);
    delay(10);
  }
  delay(500);
  gripper.write(120);
  delay(500);

  for(int i = 90; i >= 45; i--){
    elbow.write(i);
    delay(10);
  }
  delay(500);
  home();
  delay(500);
}

void home(void){
  delay(500);
  base.write(90);
  delay(500);
  shoulder.write(90);
  delay(500);
  elbow.write(90);
  delay(500);
  wristPitch.write(90);
  delay(500);
  gripper.write(5);
  delay(500);
}

 
 
  
