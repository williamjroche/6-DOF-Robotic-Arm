#include <Servo.h>

Servo base, shoulder, elbow, wristPitch, wristRoll, gripper;

int base_curpos = 90;
int shoulder_curpos = 80;
int elbow_curpos = 100;
int wristPitch_curpos = 20;
int gripper_curpos = 120;

void setup() {
  base.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wristPitch.attach(9);
  wristRoll.attach(10);
  gripper.attach(11);


//home position
  home();
}

void loop() {
  
  //move to position 1
  for(int i = 90; i<= 103; i++){
    base.write(103);
    base_curpos = i;
    delay(5);
  }
  delay(250);
  for(int i = 100; i >= 10; i--){
    elbow.write(i);
    elbow_curpos = i;
    delay(5);
  }
  delay(250);
  for(int i = 80; i <= 115; i++){
    shoulder.write(i);
    shoulder_curpos = i;
    delay(8);
  }
  delay(250);
  gripper.write(120);
  gripper_curpos = 120;
  delay(250);
  for(int i = 20; i <= 65; i++){
    wristPitch.write(i);
    wristPitch_curpos = i;
    delay(3);
  }
  delay(250);
  gripper.write(0);
  gripper_curpos = 0;
  delay(250);
  
  home();

  delay(250);
  //move to position 2
  for(int i = 90; i<=180; i++){
    base.write(i);
    base_curpos = i;
    delay(5);
  }
  delay(250);
  for(int i = 100; i >= 15; i--){
    elbow.write(i);
    elbow_curpos = i;
    delay(3);
  }
  delay(250);
  gripper.write(0);
  gripper_curpos = 0;
  delay(250);
  gripper.write(120);
  gripper_curpos = 120;
  delay(250);

  for(int i = 35; i <= 90; i++){
    elbow.write(i);
    elbow_curpos = i;
    delay(10);
  }
  
  
  home();
  delay(250);


}

void home(void){
  
  for (int i = base_curpos; i>=90; i--){
    base.write(i);
    base_curpos = i;
    delay(5);
  }
  delay(250);
  for(int i = shoulder_curpos; i>=80; i--){
    shoulder.write(i);
    shoulder_curpos = i;
    delay(10);
  }
  delay(250);
  for(int i = elbow_curpos; i<=100; i++){
    elbow.write(i);
    elbow_curpos = i;
    delay(10);
  }
  delay(250);
  for(int i = wristPitch_curpos; i>=20; i--){
    wristPitch.write(i);
    wristPitch_curpos = i;
    delay(10);
  }
  delay(250);
  if(gripper_curpos > 90){
    for(int i = gripper_curpos; i>=90; i--){
      gripper.write(i);
      gripper_curpos = i;
      delay(10);
    }
    delay(250);
  }
  else if (gripper_curpos < 90 && gripper_curpos > 0){
    for(int i = gripper_curpos; i<=90; i++){
      gripper.write(i);
      gripper_curpos = i;
      delay(10);
    }
    delay(250);
  }
  else if (gripper_curpos == 0){
    gripper.write(0);
    delay(10);
  }
  
}