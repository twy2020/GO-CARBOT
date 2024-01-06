
#define t 100    //调试延时
#define y 28.15  //调试弯角
int a = 0;
int b = 0;
int cirle_dis = 15;
int cir_color = 0;
int change_color = 0;

int get_cir_color(){
  sendInstruction(0x02);
  receiveAndProcessPacket();
  delay(100);
  return Data[2];
}

inline bool stillness() {
  while (1) {
    sendInstruction(0x02);
    delay(100);
    receiveAndProcessPacket();
    delay(50);
    //Serial.print(Data[0]);
    //Serial.print(' ');
    //Serial.print(Data[1]);
    //Serial.print(' ');
    //Serial.println(Data[2]);
    if (Data[0] != 0 && Data[1] != 0) {
      Data_last[0] = Data[0];
      Data_last[1] = Data[1];
      err_x = abs(Data_last[0] - Data[0]);
      err_y = abs(Data_last[1] - Data[1]);
      break;
    }
  }
  return 1;
}
inline bool stillness_step3() {
  while (1) {
    sendInstruction(0x01);
    delay(100);
    receiveAndProcessPacket();
    delay(50);
    if (Data[0] != 0 && Data[1] != 0) {
      Data_last[0] = Data[0];
      Data_last[1] = Data[1];
      err_x = abs(Data_last[0] - Data[0]);
      err_y = abs(Data_last[1] - Data[1]);
      break;
    }
  }
  return 1;
}
inline void stillness_1() {
  sendInstruction(0x01);
  delay(100);
  receiveAndProcessPacket();
}
inline void stillness_2() {
  sendInstruction(0x02);
  delay(100);
  receiveAndProcessPacket();
}
void Get_out()  //出库
{
  delay(200);
  moveTo(10, 4, 3100);  //左平移
  move_adjust(0.2, 50);
  delay(1000);
  moveTo(10, 4, 2000);  //左平移
  move_adjust(0.2, 50);
}


void step1_change()  //原料区校准
{
  arm.moveTo(-200);
  arm.runToPosition();
  int b = 0;
  while (b < 1) {
    int flag = stillness();
    if (flag && err_x < 5 && err_y < 5) {
      if (Data[0] > 128)  //校准x方向，物料远
        moveTo(8, 3, 300);
      if (Data[0] < 128)  //校准x方向，物料近
        moveTo(8, 4, 300);
      if (abs(128 - Data[0]) < 20)  //x方向校准完毕，校准y方向
      {

        if (Data[1] > 89)  //校准y方向，物料右
          moveTo(8, 2, 300);
        if (Data[1] < 89)  //校准y方向，物料左
          moveTo(8, 1, 300);
        if (abs(89 - Data[1]) < 20)  //y方向校准完毕，进行抓取
        {
          b = 1;
        }
      }
    }
  }
  change_color = get_cir_color();
}
void step1_action()  //原料区识别抓取
{
  int a = 0;
  //检测当前色块是否为对齐用色块，如果是，则等待下一个色块，不是，则进行抓取，避免对齐时间长而刚物块刚好移动
  while(1){
    cir_color = get_cir_color();
    if(cir_color != change_color){
      break;      
    }
  }

  while (a < 3) {
    stillness_2();
    if (Data[2] == QR_code[0] && a == 0) {
      catch_disk();
      delay(20);
      putback_disk1();
      a++;
    }
    if (Data[2] == QR_code[1] && a == 1) {
      catch_disk();
      delay(20);
      putback_disk2();
      a++;
    }
    if (Data[2] == QR_code[2] && a == 2) {
      catch_disk();
      delay(20);
      putback_disk3();
      a++;
    }
  }
}
void step1() {
  delay(500);
  moveTo(25, 4, 2000);  //左平移
  move_adjust(0.2, 35);
  moveTo(77.5, 1, 3500);  //前往二维码板    (

  while (!flag) {
    if (flag = SendData()) {
      delay(50);
      move_adjust(0.2, 50);
      break;
    }
  }
  delay(100);
  moveTo(83, 1, 3500);
  moveTo(2, 4, 3500);
  arm1();
  base.write(0);
  delay(100);

  step1_change();
  if (Data[2]) {
  }
  step1_action();
}
void step2() {
  move_adjust(0.2, 50);
  moveTo(42, 1, 3500);  //前往暂存区中间
  delay(t);

  move_adjust(0.2, 50);
  moveTo(30, 6, 3500);  //原地左转
  delay(t);
  move_adjust(89.5, 50);
}
void step3_change()  //校准
{
  int b = 0;
  while (b < 1) {
    int flag = stillness_step3();
    if (flag && err_x < 5 && err_y < 5) {
      if (Data[0] > 133)  //校准x方向，物料远
        moveTo(8, 3, 150);
      if (Data[0] < 133)  //校准x方向，物料近
        moveTo(8, 4, 130);
      if (abs(133 - Data[0]) < 10)  //x方向校准完毕，校准y方向
      {

        if (Data[1] > 89)  //校准y方向，物料右
          moveTo(8, 2, 150);
        if (Data[1] < 89)  //校准y方向，物料左
          moveTo(8, 1, 150);
        if (abs(89 - Data[1]) < 10)  //y方向校准完毕，进行抓取
        {
          b = 1;
        }
      }
    }
  }
}

/*
    当色环能够识别时用  void step3()；
     当色环不能够识别时用  void step_1()；


*/
void step3() //色环能够识别
{
  moveTo(101, 1, 3500);  //前往粗加工区中间
  moveTo(10,3,3500);
  delay(t);
  for (int i = 132; i > 0; i--) {
    base.write(i);
    delay(7);
  }
  delay(50);
  move_adjust(89.5, 50);
  code1 = QR_code[0] * 100 + QR_code[1] * 10 + QR_code[2];
  callStepFunctions(code1);
}
void step3_noview()// 色环不能够识别
{
  moveTo(101, 1, 3500);  //前往粗加工区中间
  moveTo(5,3,3500);
  delay(t);
  for (int i = 132; i > 0; i--) {
    base.write(i);
    delay(7);
  }
  delay(50);
  move_adjust(89.5, 50);
  code1 = QR_code[0] * 100 + QR_code[1] * 10 + QR_code[2];
  action(code1);
}
void step4() {
  moveTo(7, 4, 3500);
  delay(100);
  moveTo(58, 1, 3500);
  delay(100);
  moveTo(30, 6, 3500);
  delay(100);
  moveTo(93, 1, 3500);
  for (int i = 133; i > 0; i--) {
    base.write(i);
    delay(7);
  }
  step3_change();
  move_adjust(89.7 * 2, 30);
  code2 = QR_code[0] * 100 + QR_code[1] * 10 + QR_code[2];
  callStepFunctions_1(code2);
  for (int i = 0; i < 132; i++) {
    base.write(i);
    delay(7);
  }
}
void step5() {
  moveTo(5,4,3500);//平移出
  delay(100);
  move_adjust(89.7 * 2, 30);
  moveTo(93,2,3500);//回退到拐角
  delay(100);
  move_adjust(89.7 * 2, 30);
  moveTo(30, 5, 3500);//右转90
  delay(100);
  move_adjust(89.7, 30);
  moveTo(175, 2, 3500);//回退
  delay(100);
  move_adjust(89.7, 30);
  moveTo(30, 5, 3500);//右转90
  delay(100);
  move_adjust(0.2, 30);
  moveTo(45, 2, 3500);//回退至原料区
  arm1();
  base.write(0);
  delay(100);
  step1_change();
  if (Data[2]) {
  }
  step5_action();
}

void step5_action()  //原料区识别抓取
{
  int a = 0;
  //检测当前色块是否为对齐用色块，如果是，则等待下一个色块，不是，则进行抓取，避免对齐时间长而刚物块刚好移动
  while(1){
    cir_color = get_cir_color();
    if(cir_color != change_color){
      break;      
    }
  }

  while (a < 3) {
    stillness_2();
    if (Data[2] == QR_code[3] && a == 0) {
      catch_disk();
      delay(20);
      putback_disk1();
      a++;
    }
    if (Data[2] == QR_code[4] && a == 1) {
      catch_disk();
      delay(20);
      putback_disk2();
      a++;
    }
    if (Data[2] == QR_code[5] && a == 2) {
      catch_disk();
      delay(20);
      putback_disk3();
      a++;
    }
  }
}
