#include <AccelStepper.h>
#include <Servo.h>

Servo base, claw; // 创建3个舵机控制对象

const int xdirPin = 41; // 步进电机方向控制引脚
const int xstepPin = 40; // 步进电机步进控制引脚
const int xenablePin = 43; // 步进电机使能控制引脚
AccelStepper arm(1, xstepPin, xdirPin); // 建立步进电机对象

const long interval = 1000; // 1秒的延迟
int circle = 15;
void Total_Init()   //机械臂初始化
{
  pinMode(xstepPin, OUTPUT);
  pinMode(xdirPin, OUTPUT);
  pinMode(xenablePin, OUTPUT);
  digitalWrite(xenablePin, LOW);

  
  claw.attach(6);
  
  base.attach(7);// 连接底盘舵机到引脚7
  delay(200);
  base.write(133);
  //delay(10);
  claw.write(5);
  //delay(10);

  arm.setMaxSpeed(3000.0);     // 设置电机最大速度300 
  arm.setAcceleration(2000.0);  // 设置电机加速度20.0
  //initializationDone = true;
}
void catch_disk()   //原料区抓取
{

  delay(500);
  arm.moveTo(700);    //下降机械臂
  arm.runToPosition();    
  for (int i=5; i<90; i++)
  {
  claw.write(i);
  delay(5);
  }
  arm.moveTo(-550);   //升高
  arm.runToPosition(); 
}
void putback_disk1()    //原料区放第一个物料到车
{
  for (int i=0; i<152; i++) //放到last
  {
  base.write(i);
  delay(10);
  }
  arm.moveTo(200);    //放下机械臂
  arm.runToPosition();   
  claw.write(75);   //松爪
  arm.moveTo(-540);   //升高
  arm.runToPosition();   
  delay(100);
  claw.write(5);
  for (int i=152; i>0; i--)
  {
  base.write(i);
  delay(10);
  }
}
void putback_disk2()    //原料区放第二个物料到车
{
  for (int i=0; i<133; i++)   //放到mid
  {
  base.write(i);
  delay(10);
  }
  arm.moveTo(200);    //放下机械臂
  arm.runToPosition();
  claw.write(75);   //松爪
  arm.moveTo(-540);   //升高
  arm.runToPosition();    
  delay(100);
  claw.write(5);
  for (int i=133; i>0; i--)
  {
  base.write(i);
  delay(10);
  }
}
void putback_disk3()    //原料区放第二个物料到车
{
  for (int i=0; i<112; i++)
  {
  base.write(i);
  delay(10);
  }
  arm.moveTo(200);    //放下机械臂
  arm.runToPosition();
  claw.write(75);   //松爪
  arm.moveTo(-540);   //升高
  arm.runToPosition();
  delay(100);
  claw.write(5);
  for (int i=112; i<133; i++)
  {
  base.write(i);
  delay(10);
  } 
}
void catch_disk21()   //放置第一物料
{
  arm.moveTo(-655);   //上升630
  arm.runToPosition();  
  claw.write(75);   //爪子恢复到正好抓取物料底部大小
  for (int i=0; i<152; i++)   //复位点到达first
  {
  base.write(i);
  delay(10);
  }
  arm.moveTo(1800);   //下降到物料底部
  arm.runToPosition();  
  for (int i=75; i<90; i++)   //从first关闭爪
  {
  claw.write(i);
  delay(10);
  }
  arm.moveTo(-700);   //上升至物料顶端
  arm.runToPosition();  
  for (int i=153; i>0; i--) //从first抓出到前端
  {
  base.write(i);
  delay(15);
  }
  arm.moveTo(5100);  //机械臂到达最低点
  arm.runToPosition();
  for (int i=90; i>70; i--)   //缓慢松爪
  {
  claw.write(i);
  delay(10);
  }
}
void catch_disk22()   //放置第二物料
{
  arm.moveTo(-655);   //上升630
  arm.runToPosition();  
  claw.write(75);   //爪子恢复到正好抓取物料底部大小
  for (int i=0; i<133; i++)   //复位点到达mid
  {
  base.write(i);
  delay(10);
  }
  arm.moveTo(1800);   //下降到物料底部
  arm.runToPosition();  
  for (int i=75; i<90; i++)   //从mid关闭爪
  {
  claw.write(i);
  delay(10);
  }
  arm.moveTo(-700);   //上升至物料顶端
  arm.runToPosition();  
  for (int i=133; i>0; i--) //从mid抓出到前端
  {
  base.write(i);
  delay(20);
  }
  arm.moveTo(5100);  //机械臂到达最低点
  arm.runToPosition();
  for (int i=90; i>70; i--)   //缓慢松爪
  {
  claw.write(i);
  delay(10);
  }
}
void catch_disk23()   //放置第三物料
{
  arm.moveTo(-655);   //上升630
  arm.runToPosition();  
  claw.write(75);   //爪子恢复到正好抓取物料底部大小
  for (int i=0; i<114; i++)   //复位点到达last
  {
  base.write(i);
  delay(10);
  }
  arm.moveTo(1800);   //下降到物料底部
  arm.runToPosition();  
  for (int i=75; i<90; i++)   //从last关闭爪
  {
  claw.write(i);
  delay(10);
  }
  arm.moveTo(-700);   //上升至物料顶端
  arm.runToPosition();  
  for (int i=112; i>0; i--) //从last抓出到前端
  {
  base.write(i);
  delay(15);
  }
  arm.moveTo(5100);  //机械臂到达最低点
  arm.runToPosition();
  for (int i=90; i>70; i--)   //缓慢松爪
  {
  claw.write(i);
  delay(10);
  }
}
void catch_back1()  //粗加工区回收第一物料
{
  claw.write(5);    //张开爪子
  arm.moveTo(4300);   //对准物料
  arm.runToPosition();
  for (int i=5; i<89; i++)    //抓住物料
  {
  claw.write(i);
  delay(7);
  } 
  arm.moveTo(-645);   //升高机械臂
  arm.runToPosition();
  for (int i=0; i<152; i++)    //放至first上方
  {
  base.write(i);
  delay(10);
  } 
  arm.moveTo(200);   //对准物料
  arm.runToPosition();
  for (int i=89; i>75; i--)    //缓慢松爪
  {
  claw.write(i);
  delay(10);
  }
  arm.moveTo(-645);   //升高机械臂
  arm.runToPosition();
  for (int i=152; i>0; i--)    //缓慢松爪
  {
  base.write(i);
  delay(15);
  }
}
void catch_back2()  //粗加工区回收第二物料
{
  claw.write(5);    //张开爪子
  arm.moveTo(4300);   //对准物料
  arm.runToPosition();
  for (int i=5; i<89; i++)    //抓住物料
  {
  claw.write(i);
  delay(7);
  } 
  arm.moveTo(-645);   //升高机械臂
  arm.runToPosition();
  for (int i=0; i<133; i++)    //放至mid上方
  {
  base.write(i);
  delay(10);
  } 
  arm.moveTo(200);   //对准物料
  arm.runToPosition();
  for (int i=89; i>75; i--)    //缓慢松爪
  {
  claw.write(i);
  delay(10);
  }
  arm.moveTo(-645);   //升高机械臂
  arm.runToPosition();
  for (int i=133; i>0; i--)    //缓慢松爪
  {
  base.write(i);
  delay(15);
  }
}
void catch_back3()  //粗加工区回收第三物料
{
  claw.write(5);    //张开爪子
  arm.moveTo(4300);   //对准物料
  arm.runToPosition();
  for (int i=5; i<89; i++)    //抓住物料
  {
  claw.write(i);
  delay(7);
  } 
  arm.moveTo(-645);   //升高机械臂
  arm.runToPosition();
  for (int i=0; i<112; i++)    //放至mid上方
  {
  base.write(i);
  delay(10);
  } 
  arm.moveTo(200);   //对准物料
  arm.runToPosition();
  for (int i=89; i>75; i--)    //缓慢松爪
  {
  claw.write(i);
  delay(10);
  }
  arm.moveTo(-645);   //升高机械臂
  arm.runToPosition();
  for (int i=112; i>0; i--)    //缓慢松爪
  {
  base.write(i);
  delay(15);
  }
}
void arm1()
{
  arm.moveTo(-500);
  arm.runToPosition();
}
/////////////////////////////////////绿色起点////////////////////////////////////
void action_123() //红绿蓝
{
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  putback_disk1();
  moveTo(circle,1,3500);   //前往绿
  move_adjust(89.5,100);
  putback_disk2();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  putback_disk3();
  moveTo(circle*2,2,3500);   //回到红
  move_adjust(89.5,100);
}
void action_132() //红蓝绿
{
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  putback_disk1();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
  putback_disk2();
  moveTo(circle,2,3500);   //前往绿
  move_adjust(89.5,100);
  putback_disk3();
  moveTo(circle,2,3500);   //回到红
  move_adjust(89.5,100);
}
void action_213() //绿红蓝
{
  move_adjust(89.5,100);    //绿色原地放下
  putback_disk1();
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  putback_disk2();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
  putback_disk3();
  moveTo(circle,2,3500);   //前往绿
  move_adjust(89.5,100);
}
void action_231() //绿蓝红
{
  move_adjust(89.5,100);    //绿色原地放下
  putback_disk1();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  putback_disk2();
  moveTo(circle*2,2,3500);   //前往红
  move_adjust(89.5,100);
  putback_disk3();
  moveTo(circle,1,3500);   //回到绿
  move_adjust(89.5,100);
}
void action_321() //蓝绿红
{
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  putback_disk1();
  moveTo(circle,2,3500);   //前往绿
  move_adjust(89.5,100);
  putback_disk2();
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  putback_disk3();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
}
void action_312() //蓝红绿
{
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  putback_disk1();
  moveTo(circle*2,2,3500);   //前往红
  move_adjust(89.5,100);
  putback_disk2();
  moveTo(circle,1,3500);   //前往绿
  move_adjust(89.5,100);
  putback_disk3();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
}
///////////////////////////////////绿色起点回收/////////////////////////////////////
void action1_123() //红绿蓝
{
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  catch_back1();
  moveTo(circle,1,3500);   //前往绿
  move_adjust(89.5,100);
  catch_back2();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  catch_back3();    
  move_adjust(89.5,100);    //原地校准
}
void action1_132() //红蓝绿
{
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  catch_back1();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
  catch_back2();
  moveTo(circle,2,3500);   //前往绿
  move_adjust(89.5,100);
  catch_back3();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
}
void action1_213() //绿红蓝
{
  move_adjust(89.5,100);    //绿色原地放下
  catch_back1();
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  catch_back2();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
  catch_back3();
  move_adjust(89.5,100);    //原地校准
}
void action1_231() //绿蓝红
{
  move_adjust(89.5,100);    //绿色原地放下
  catch_back1();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  catch_back2();
  moveTo(circle*2,2,3500);   //前往红
  move_adjust(89.5,100);
  catch_back3();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
}
void action1_321() //蓝绿红
{
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  catch_back1();
  moveTo(circle,2,3500);   //前往绿
  move_adjust(89.5,100);
  catch_back2();
  moveTo(circle,2,3500);   //前往红
  move_adjust(89.5,100);
  catch_back3();
  moveTo(circle*2,1,3500);   //前往蓝
  move_adjust(89.5,100);
}
void action1_312() //蓝红绿
{
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
  catch_back1();
  moveTo(circle*2,2,3500);   //前往红
  move_adjust(89.5,100);
  catch_back2();
  moveTo(circle,1,3500);   //前往绿
  move_adjust(89.5,100);
  catch_back3();
  moveTo(circle,1,3500);   //前往蓝
  move_adjust(89.5,100);
}
///////////////////////////////////动作函数//////////////////////////////////////////////
void a123()
{
  action_123();
  action1_123();
}
void a132()
{
  action_132();
  action1_132();
}
void a213()
{
  action_213();
  action1_213();
}
void a231()
{
  action_231();
  action1_231();
}
void a312()
{
  action_312();
  action1_312();
}
void a321()
{
  action_321();
  action1_321();
}
void action(int n) 
{
    switch (n) {
        case 123:
            a123();
            break;
        case 132:
             a132();
            break;
        case 213:
            a213();
            break;
        case 231:
            a231();
            break;
        case 321:
            a321();
            break;
        case 312:
            a312();
            break;
        default:
            // Handle the case where the code doesn't match any of the above cases
            break;
    }
}

