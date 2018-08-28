#include <TimerOne.h>
#include <Wire.h>
#include <JY901.h>
#include "servo.h"
#include "gyro.h"
#include "esp.h"

msg jumperMsg;
msg* jy901Data = &jumperMsg;

String rcv_msg = ""; 

char serial3Receive = "";
//int serial3Receive = 0;
/*str1.equals(str2)*///字符串函数比较--str1.equalslgnoreCase(str2)//忽略大小写
char cmd[2];//匹配指令集

//串口中断函数
//void serialEvent() {
//  while (Serial3.available()) {
//    serial3Receive = Serial3.read();
//    if(serial3Receive == "1")
//    {
//      Serial.print("cmd=1");
//      }
//  }
//}

void setup() 
{
  Serial.begin(115200);
  Serial3.begin(115200);
  while(!Serial);
  while (!Serial3);
  JY901.StartIIC();

  servoInit();
  ESP_INIT();
  
//  rcv_msg = ESP_INIT();
//  while(!rcv_msg.startsWith("OK")){
//    rcv_msg = ESP_INIT();
//  }

  Timer1.initialize(50000); // set a timer of length 100000 microsecond微秒
  Timer1.attachInterrupt( mixMsgSend );
} 

void loop() 
{
  jumperMsg = msgRead();//读取陀螺仪信息
  //delay(20);
  //mixMsgSend();
  //servoTest(90);
  //cmdAction(serial3Receive);
}



