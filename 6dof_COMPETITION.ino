#include <Servo.h>

Servo base, shoulder, elbow, wristPitch, wristRoll, gripper;

int base_curpos = 90;
int shoulder_curpos = 90;
int elbow_curpos = 90;
int wristPitch_curpos = 90;
int gripper_curpos = 90;

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
  base.write(103);
  base_curpos = 103;
  delay(500);
  for(int i = 90; i <= 115; i++){
    shoulder.write(i);
    shoulder_curpos = i;
    delay(10);
  }
  delay(500);
  gripper.write(120);
  delay(500);
  for(int i = 90; i >= 10; i--){
    elbow.write(i);
    elbow_curpos = i;
    delay(10);
  }
  delay(500);
  for(int i = 90; i >= 65; i--){
    wristPitch.write(i);
    wristPitch_curpos = i;
    delay(10);
  }
  delay(500);
  gripper.write(0);
  gripper_curpos = 0;
  delay(500);
  
  home();

  delay(1000);
  //move to position 2
  for(int i = 90; i<=180; i++){
    base.write(i);
    base_curpos = i;
    delay(10);
  }
  delay(500);
  for(int i = 90; i <= 122 ; i++){
    shoulder.write(i);
    shoulder_curpos = i;
    delay(10);
  }
  delay(500);
  gripper.write(0);
  gripper_curpos = 0;
  delay(500);
  for(int i = 90; i >= 35; i--){
    elbow.write(i);
    elbow_curpos = i;
    delay(10);
  }
  delay(500);
  gripper.write(120);
  gripper_curpos = 120;
  delay(500);

  for(int i = 35; i <= 90; i++){
    elbow.write(i);
    elbow_curpos = i;
    delay(10);
  }
  delay(500);
  home();
  delay(500);


}

void home(void){
  delay(500);
  for (int i = base_curpos; i>=90; i--){
    base.write(i);
    base_curpos = i;
    delay(10);
  }
  delay(500);
  for(int i = shoulder_curpos; i>=90; i--){
    shoulder.write(i);
    shoulder_curpos = i;
    delay(10);
  }
  delay(500);
  for(int i = elbow_curpos; i<=90; i++){
    elbow.write(i);
    elbow_curpos = i;
    delay(10);
  }
  delay(500);
  for(int i = wristPitch_curpos; i<=90; i++){
    wristPitch.write(i);
    wristPitch_curpos = i;
    delay(10);
  }
  delay(500);
  if(gripper_curpos > 90){
    for(int i = gripper_curpos; i>=90; i--){
      gripper.write(i);
      gripper_curpos = i;
      delay(10);
    }
    delay(500);
  }
  else if (gripper_curpos < 90 && gripper_curpos > 0){
    for(int i = gripper_curpos; i<=90; i++){
      gripper.write(i);
      gripper_curpos = i;
      delay(10);
    }
    delay(500);
  }
  else if (gripper_curpos == 0){
    gripper.write(0);
    delay(10);
  }
  delay(500);
}