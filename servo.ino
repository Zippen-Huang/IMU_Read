#include <Servo.h>

Servo servo1; 
Servo servo2;

unsigned char pos_1 = 60; //the speed of energy storage
unsigned char pos_2 = 120;//the speed of energy release
unsigned char pos_3 = 0;
unsigned char pos_4 = 180;//the speed of screw 

void servoInit(){
  servo1.attach(9); 
  servo2.attach(10);
}

void Storage()//储能->阶段1
{
  servo1.write(pos_1);
}

void Release()//释放
{
  servo1.write(pos_2);
}
void Screwgo()//储能—>阶段2 
{ 
  servo2.write(pos_3);
}

void Screwback()//丝杆复位
{
  
  servo2.write(pos_4);
}

void servoStop()
{
  servo1.write(92);
  servo2.write(92);
}

void servoTest(char i){
  servo1.write(i);
  servo2.write(180-i);
}

