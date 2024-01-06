#include <Arduino.h>
#include <AccelStepper.h>
float line_v = 3500;
float lin_v = 35;
/*--------------------- 设置步进引脚 -------------------------------------*/

const int enablePin = 42;
const int step1Pin = 32;
const int dir1Pin = 33;
const int step2Pin = 34;
const int dir2Pin = 35;
const int step3Pin = 36;
const int dir3Pin = 37;
const int step4Pin = 38;
const int dir4Pin = 39;

/*-------------------- 创建AccelStepper对象 ------------------------------*/

AccelStepper stepper1(1, step1Pin, dir1Pin);
AccelStepper stepper2(1, step2Pin, dir2Pin);
AccelStepper stepper3(1, step3Pin, dir3Pin);
AccelStepper stepper4(1, step4Pin, dir4Pin);

/*-------------------- 电机初始化 -----------------------------------------*/

void Motor_Init() {
  setpin();
  setMaxSpeed();
  setspeed();
}
void setpin() {
  pinMode(step1Pin, OUTPUT);  // Arduino控制A4988步进引脚为输出模式
  pinMode(dir1Pin, OUTPUT);   // Arduino控制A4988方向引脚为输出模式
  pinMode(step2Pin, OUTPUT);  // Arduino控制A4988步进引脚为输出模式
  pinMode(dir2Pin, OUTPUT);   // Arduino控制A4988方向引脚为输出模式
  pinMode(step3Pin, OUTPUT);  // Arduino控制A4988步进引脚为输出模式
  pinMode(dir3Pin, OUTPUT);   // Arduino控制A4988方向引脚为输出模式
  pinMode(step4Pin, OUTPUT);  // Arduino控制A4988步进引脚为输出模式
  pinMode(dir4Pin, OUTPUT);   // Arduino控制A4988方向引脚为输出模式

  pinMode(enablePin, OUTPUT);    // Arduino控制A4988使能引脚为输出模式
  digitalWrite(enablePin, LOW);  // 将使能控制引脚设置为低电平从而让
}
void setMaxSpeed() {
  stepper1.setMaxSpeed(line_v);
  stepper2.setMaxSpeed(line_v);
  stepper3.setMaxSpeed(-line_v);
  stepper4.setMaxSpeed(-line_v);
}
inline void setspeed() {
  stepper1.setSpeed(line_v);
  stepper2.setSpeed(line_v);
  stepper3.setSpeed(-line_v);
  stepper4.setSpeed(-line_v);
}
inline void runspeed() {
  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();
  stepper4.runSpeed();
}
/*--------------------- 舵机引脚初始化 -----------------------------------*/

/*-------------------- 移动函数 -----------------------------------------*/
void update_101(){
  while (hwt101.available()) 
  {
    JY901.CopeSerialData( hwt101.read()); // 调用 JY901 数据处理函数
    
  }

  // 储存数据
  Gyro = (float)JY901.stcGyro.w[2] / 32768 * 2000;
  yaw = (float)JY901.stcAngle.Angle[2] / 32768 * 180;
  err=yaw-target;
  /*Serial.print("Gyro:");
  Serial.println(Gyro);
  Serial.print("Angle:");
  Serial.println(yaw);*/
  Serial.print("err:");
  Serial.println(err);
}
inline void xySetVal(double v0, int dir)  //  给定速度 + 方向
{
  switch (dir) 
  {  // 设定行进方向集步进数
    case 1:       // 1 前
      stepper1.setSpeed(v0);
      stepper2.setSpeed(v0);
      stepper3.setSpeed(-v0);
      stepper4.setSpeed(-v0);
      break;
    case 2:  // 2  后
      stepper1.setSpeed(-v0);
      stepper2.setSpeed(-v0);
      stepper3.setSpeed(v0);
      stepper4.setSpeed(v0);
      break;
    case 3:  //  3  右
      stepper1.setSpeed(-v0);
      stepper2.setSpeed(v0);
      stepper3.setSpeed(v0);
      stepper4.setSpeed(-v0);
      break;
    case 4:  //  4  左
      stepper1.setSpeed(v0);
      stepper2.setSpeed(-v0);
      stepper3.setSpeed(-v0);
      stepper4.setSpeed(v0);
      break;
    case 5:  // 1 原地右
      stepper1.setSpeed(-v0);
      stepper2.setSpeed(-v0);
      stepper3.setSpeed(-v0);
      stepper4.setSpeed(-v0);
      break;
    case 6:  // 1 原地左
      stepper1.setSpeed(v0);
      stepper2.setSpeed(v0);
      stepper3.setSpeed(v0);
      stepper4.setSpeed(v0);
      break;

    default: break;
  }
}
inline void xysetVal(double v1, int dir)  //  给定速度 + 方向
{

  switch (dir) 
  {  // 设定行进方向集步进数
    case 1:       // 1 前
      stepper1.setSpeed(v1);
      stepper2.setSpeed(v1);
      stepper3.setSpeed(-v1);
      stepper4.setSpeed(-v1);


      break;
    case 2:  // 2  后
      stepper1.setSpeed(-v1);
      stepper2.setSpeed(-v1);
      stepper3.setSpeed(v1);
      stepper4.setSpeed(v1);

      break;
    case 3:  //  3  右
      stepper1.setSpeed(-v1);
      stepper2.setSpeed(v1);
      stepper3.setSpeed(v1);
      stepper4.setSpeed(-v1);

      break;
    case 4:  //  4  左
      stepper1.setSpeed(v1);
      stepper2.setSpeed(-v1);
      stepper3.setSpeed(-v1);
      stepper4.setSpeed(v1);

      break;
    case 5:  // 5 原地右
      stepper1.setSpeed(-v1);
      stepper2.setSpeed(-v1);
      stepper3.setSpeed(-v1);
      stepper4.setSpeed(-v1);

      break;
    case 6:  // 6 原地左
      stepper1.setSpeed(v1);
      stepper2.setSpeed(v1);
      stepper3.setSpeed(v1);
      stepper4.setSpeed(v1);

      break;

    default: break;
  }
}
void stopHalfSec()  //  小车停止
{
  xySetVal(0, 0);
  runspeed();
}
void moveTo(double dxy, int dir, double v) {
  if (dxy == 0) return;
  double t1 = ((3 * dxy) / 66.92) * 870;
  if (t1 == 0) return;  // 防止发生不可预料的错误
  xySetVal(v, dir);  // 使用传入的 v 来设置 line_v
  // 步进电机持续转动时间&#8203;``oaicite:{"number":1,"invalid_reason":"Malformed citation 【 t1 * 870 】"}``&#8203;
  unsigned long delta_t = millis() + t1;  //  millis()-ms-1000   870-修正系数
  while (millis() < delta_t) {
    runspeed();  // 步进电机开始转动。（前边设定步进及速度）
  }
  stopHalfSec();  // 速度为零
}
void move_adjust(double dir_angle, double v) //速度可调的校准角度
{
    while (fabs(err) > dir_angle) {
        if (err > dir_angle) {
            // 逆时针校准逻辑 - 减小方向
            xysetVal(v, 6); // 设置步进电机速度和方向
            runspeed(); // 启动步进电机
        } else if (err < dir_angle) {
            // 顺时针校准逻辑 - 增大方向
            xysetVal(v, 5); // 设置步进电机速度和方向
            runspeed(); // 启动步进电机
        }
        stopHalfSec(); // 停止一段时间，以允许校准发生
    }
    // 停止步进电机或者执行其他必要的操作，校准完成
}