#include <AccelStepper.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <FlexiTimer2.h>
#include <Wire.h>
#include <JY901.h>      
#include <string.h>

#define PACKET_SIZE 9  // 数据包大小（包括帧头、数据、帧尾）
#define hwt101 Serial1 //hwt101 串口1
#define openmv   Serial2 //openmv 串口3
#define v831     Serial3//openmv 串口2
int Data[3]; // 用于存储提取的数据
int Data_last[2];

int err_x,err_y;
int x_target = 0;
int y_target = 0;

SoftwareSerial Screen(50, 51); // RX, TX

int QR_code[6];  // 用于存储接收到的数字数据


float yaw_0 = 0;
double yaw;   // 当前角度数据  
float Gyro;  // 当前角加速度 
// 创建Servo对象
double target=0;
double err=yaw-target;


char str[100];
bool flag= false;
int code1,code2,code3;

void setup() 
{
/*-----------------------串口初始化-----------------------------------------------*/
  hwt101.begin(9600);   // 初始化串口1  陀螺仪
  openmv.begin(9600);     // 初始化串口2  openmv
  v831.begin(57600);   // 初始化串口3 1
  Screen.begin(9600);     // 初始化串口4  串口屏
  Serial.begin(115200);
  
  FlexiTimer2::set(200, 1.0 / 1000, update_101); // 50ms太卡。每xx*1ms执行一次Event
  FlexiTimer2::start();    // 开中断   50ms20Hz-太卡  200ms5Hz- 依旧有些咔咔咔
  
  Motor_Init();
  Total_Init();
  step1();
  step2();
  step3_noview();
  step4();
  step5();
}

void loop()
{      
}
bool SendData()
{
   
  if (openmv.available() >= PACKET_SIZE) {
    byte header1 = openmv.read();
    byte header2 = openmv.read();

    if (header1 == 0x5A && header2 == 0x5B) {
      for (int i = 0; i < 6; i++) {
        QR_code[i] = openmv.read();
      }

      byte footer = openmv.read();

      if (footer == 0x5C) {
        int data0 = QR_code[0] * 100 + QR_code[1] * 10 + QR_code[2];
        int data1 = QR_code[3] * 100 + QR_code[4] * 10 + QR_code[5];

        sendDataToScreen(data0, data1);
        return true; // 数据成功接收并处理
      } else {
        // 帧尾不匹配，丢弃数据包
      }
    } else {
      // 帧头不匹配，丢弃数据包
    }
  }
  return false; // 没有接收到有效数据
}
void sendDataToScreen(int data0, int data1)
{
  char str[100];

  // 构造发送数据
  sprintf(str, "n0.val=%d\xff\xff\xff", data0);
  Screen.print(str);
  sprintf(str, "n1.val=%d\xff\xff\xff", data1);
  Screen.print(str);
  Serial.print(data0);
  Serial.println(data1);
}
