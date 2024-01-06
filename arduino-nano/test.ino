
void step3_puttask_213()    //粗加工区放置物料213
{
  stillness_1();
  while(QR_code[0] != Data[2])
  {
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //213 绿 红 蓝
  {
    step3_change();  //校准圆心
    catch_disk21();   //2绿 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7,100);   //陀螺仪校准
    moveTo(cirle_dis, 2, 3500);  //回退1红
    move_adjust(89.7,100);               //陀螺仪校准
    stillness_1();               //收发一次数据
    while(QR_code[1] != Data[2])
    {  
    stillness_1();
    }
    if (QR_code[1] == Data[2]) {
      step3_change();                  //校准圆心
      catch_disk22();                   //1红 执行放置
      arm.moveTo(-645);   //抬起机械臂
      arm.runToPosition();
      delay(50);
      move_adjust(89.7,100);                   //陀螺仪校准
      moveTo(cirle_dis * 2, 1, 3500);  //前进3蓝
      move_adjust(89.7,100);                   //陀螺仪校准
      stillness_1();                   //收发一次数据
      while(QR_code[2] != Data[2])
      {
      stillness_1();
      }
      if (QR_code[2] == Data[2]) {
        step3_change();  //校准圆心
        catch_disk23();   //3蓝 执行放置
        arm.moveTo(-645);   //抬起机械臂
        arm.runToPosition();
        delay(50);
        move_adjust(89.7,100);   //陀螺仪校准 
        moveTo(cirle_dis , 2, 3500);  //回到绿色中心
        move_adjust(89.7,100);        //陀螺仪校准
      }
    }
  }
}
void step3_catchtask_213()    //粗加工区回收物料213
{
  catch_back1();
  moveTo(cirle_dis, 2, 3500);  //回退1红
  move_adjust(89.7, 100);      //陀螺仪校准
  catch_back2();
  moveTo(cirle_dis * 2, 1, 3500);  //前进3蓝
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back3();
  step3_change();  //校准圆心
  for (int i=0; i<133; i++)
  {
  base.write(i);
  delay(7);
  }
  move_adjust(89.7, 100);          //陀螺仪校准
}
void step3_puttask_231()    //粗加工区放置物料231
{
  stillness_1();
  while(QR_code[0] != Data[2])
  {
   
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //231 绿 蓝 红
  {
    step3_change();  //校准圆心
    catch_disk21();   //2绿 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7,100);   //陀螺仪校准
    moveTo(cirle_dis, 1, 3500);  //前进3蓝
    move_adjust(89.7,100);               //陀螺仪校准
    stillness_1();               //收发一次数据
    while(QR_code[1] != Data[2])
    {
    
    stillness_1();
    }
    if (QR_code[1] == Data[2]) {
      step3_change();                  //校准圆心
      catch_disk22();                   //3蓝 执行放置
      arm.moveTo(-645);   //抬起机械臂
      arm.runToPosition();
      delay(50);
      move_adjust(89.7,100);                   //陀螺仪校准
      moveTo(cirle_dis * 2, 2, 3500);  //回退1红
      move_adjust(89.7,100);                   //陀螺仪校准
      stillness_1();                   //收发一次数据
      while(QR_code[2] != Data[2])
      {
      
      stillness_1();
      }
      if (QR_code[2] == Data[2]) {
        step3_change();  //校准圆心
        catch_disk23();   //1红 执行放置
        arm.moveTo(-645);   //抬起机械臂
        arm.runToPosition();
        delay(50);
        move_adjust(89.7,100);   //陀螺仪校准 
        moveTo(cirle_dis,1,3500);   //前往绿色中心
        move_adjust(89.7,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_catchtask_231()    //粗加工区回收物料231
{
  catch_back1();
  moveTo(cirle_dis, 1, 3500);  //前进3蓝
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back2();
  moveTo(cirle_dis * 2, 2, 3500);  //回退1红
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back3();
  moveTo(cirle_dis * 2, 1, 3500);  //前进3蓝
  step3_change();  //校准圆心
  for (int i=0; i<133; i++)
  {
  base.write(i);
  delay(7);
  }
  move_adjust(89.7, 100);          //陀螺仪校准
}
void step3_puttask_123()    //粗加工区放置物料123
{
  moveTo(cirle_dis, 2, 3500);
  stillness_1();
  while(QR_code[0] != Data[2])
  {
    
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //123 红 绿 蓝
  { 
    moveTo(cirle_dis, 2, 3500); 
    step3_change();  //校准圆心
    catch_disk21();   //1红 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7,100);   //陀螺仪校准
    moveTo(cirle_dis, 1, 3500);  //前进2绿
    move_adjust(89.7,100);               //陀螺仪校准
    stillness_1();               //收发一次数据
    while(QR_code[1] != Data[2])
    {
    
    stillness_1();
    }
    if (QR_code[1] == Data[2]) {
      step3_change();                  //校准圆心
      catch_disk22();                   //2绿 执行放置
      arm.moveTo(-645);   //抬起机械臂
      arm.runToPosition();
      delay(50);
      move_adjust(89.7,100);                   //陀螺仪校准
      moveTo(cirle_dis, 1, 3500);  //前进3蓝
      move_adjust(89.7,100);                   //陀螺仪校准
      stillness_1();                   //收发一次数据
      while(QR_code[2] != Data[2])
      {
      
      stillness_1();
      }
      if (QR_code[2] == Data[2]) {
        step3_change();  //校准圆心
        catch_disk23();   //3蓝 执行放置
        arm.moveTo(-645);   //抬起机械臂
        arm.runToPosition();
        delay(50);
        move_adjust(89.7,100);   //陀螺仪校准 
        moveTo(cirle_dis *2 ,2,3500);   //回到红色中心
        move_adjust(89.7,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_catchtask_123()    //粗加工区回收物料123
{
  catch_back1();
  moveTo(cirle_dis, 1, 3500);  //前进2绿
  move_adjust(89.7, 100);      //陀螺仪校准
  catch_back2();
  moveTo(cirle_dis , 1, 3500);  //前进3蓝
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back3();
  step3_change();  //校准圆心
  for (int i=0; i<133; i++)
  {
  base.write(i);
  delay(7);
  }
  move_adjust(89.7, 100);          //陀螺仪校准
}
void step3_puttask_132()    //粗加工区放置物料132///////////////////////////////
{
  moveTo(cirle_dis, 2, 3500);
  stillness_1();
  while(QR_code[0] != Data[2])
  {
    
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //132 红 蓝 绿 
  { 
    step3_change();  //校准圆心
    catch_disk21();   //1红 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7,100);   //陀螺仪校准
    moveTo(cirle_dis*2, 1, 3500);  //前进3蓝
    move_adjust(89.7,100);               //陀螺仪校准
    stillness_1();               //收发一次数据
    while(QR_code[1] != Data[2])
    {
    
    stillness_1();
    }
    if (QR_code[1] == Data[2]) {
      step3_change();                  //校准圆心
      catch_disk22();                   //3蓝 执行放置
      arm.moveTo(-645);   //抬起机械臂
      arm.runToPosition();
      delay(50);
      move_adjust(89.7,100);                   //陀螺仪校准
      moveTo(cirle_dis, 2, 3500);  //前进2绿
      move_adjust(89.7,100);                   //陀螺仪校准
      stillness_1();                   //收发一次数据
      while(QR_code[2] != Data[2])
      {
      
      stillness_1();
      }
      if (QR_code[2] == Data[2]) {
        step3_change();  //校准圆心
        catch_disk23();   //2绿 执行放置
        arm.moveTo(-645);   //抬起机械臂
        arm.runToPosition();
        delay(50);
        moveTo(cirle_dis, 2, 3500); //回退红色
        step3_change();  //校准圆心
        move_adjust(89.7,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_catchtask_132()    //粗加工区回收物料132
{
  catch_back1();
  moveTo(cirle_dis * 2, 1, 3500);  //前进3蓝
  move_adjust(89.7, 100);      //陀螺仪校准
  catch_back2();
  moveTo(cirle_dis, 2, 3500);  //回退2绿
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back3();
  moveTo(cirle_dis, 1, 3500);  //前往蓝色中心
  step3_change();  //校准圆心
  for (int i=0; i<133; i++)
  {
  base.write(i);
  delay(7);
  }
  move_adjust(89.7, 100);//陀螺仪校准
}
void step3_puttask_312()    //粗加工区放置物料312
{
  moveTo(cirle_dis, 1, 3500);
  step3_change();  //校准圆心
  move_adjust(89.7, 100);//陀螺仪校准
  stillness_1();
  while(QR_code[0] != Data[2])
  {
    
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //312 蓝 红 绿
  {
    step3_change();  //校准圆心
    catch_disk21();   //3蓝 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7,100);   //陀螺仪校准
    moveTo(cirle_dis * 2, 2, 3500);  //回退1红
    move_adjust(89.7,100);               //陀螺仪校准
    stillness_1();               //收发一次数据
    while(QR_code[1] != Data[2])
    {
   
    stillness_1();
    }
    if (QR_code[1] == Data[2]) {
      step3_change();                  //校准圆心
      catch_disk22();                   //1红 执行放置
      arm.moveTo(-645);   //抬起机械臂
      arm.runToPosition();
      delay(50);
      move_adjust(89.7,100);                   //陀螺仪校准
      moveTo(cirle_dis , 1, 3500);  //前进2绿
      move_adjust(89.7,100);                   //陀螺仪校准
      stillness_1();                   //收发一次数据
      while(QR_code[2] != Data[2])
      {
      
      stillness_1();
      }
      if (QR_code[2] == Data[2]) {
        step3_change();  //校准圆心
        catch_disk23();   //2绿 执行放置
        arm.moveTo(-645);   //抬起机械臂
        arm.runToPosition();
        delay(50);
        move_adjust(89.7,100);   //陀螺仪校准 
        moveTo(cirle_dis,1,3500);   //前往蓝色中心
        step3_change();  //校准圆心
        move_adjust(89.7,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_catchtask_312()    //粗加工区回收物料312
{
  catch_back1();
  moveTo(cirle_dis*2, 2, 3500);  //回退1红
  move_adjust(89.7, 100);      //陀螺仪校准
  catch_back2();
  moveTo(cirle_dis , 1, 3500);  //前进2绿
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back3();
  moveTo(cirle_dis , 1, 3500);  //前进3蓝
  step3_change();  //校准圆心
  for (int i=0; i<133; i++)
  {
  base.write(i);
  delay(7);
  }
  move_adjust(89.7, 100);          //陀螺仪校准
}
void step3_puttask_321()    //粗加工区放置物料321
{
  moveTo(cirle_dis,1,3500);
  stillness_1();
  while(QR_code[0] != Data[2])
  {
   
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //321  蓝 绿 红
  {
    step3_change();  //校准圆心
    catch_disk21();   //3蓝 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7,100);   //陀螺仪校准
    moveTo(cirle_dis, 2, 3500);  //回退2绿
    move_adjust(89.7,100);               //陀螺仪校准
    stillness_1();               //收发一次数据
    while(QR_code[1] != Data[2])
    {
    moveTo(10,1,1000);
    delay(500);
    moveTo(10,2,1000);
    delay(500);
    stillness_1();
    }
    if (QR_code[1] == Data[2]) {
      step3_change();                  //校准圆心
      catch_disk22();                   //2绿 执行放置
      arm.moveTo(-645);   //抬起机械臂
      arm.runToPosition();
      delay(50);
      move_adjust(89.7,100);                   //陀螺仪校准
      moveTo(cirle_dis , 2, 3500);  //回退1红
      move_adjust(89.7,100);                   //陀螺仪校准
      stillness_1();                   //收发一次数据
      while(QR_code[2] != Data[2])
      {
      
      stillness_1();
      }
      if (QR_code[2] == Data[2]) {
        step3_change();  //校准圆心
        catch_disk23();   //1红 执行放置
        arm.moveTo(-645);   //抬起机械臂
        arm.runToPosition();
        delay(50);
        move_adjust(89.7,100);   //陀螺仪校准 
        moveTo(cirle_dis*2,1,3500);   //回到蓝中心
        move_adjust(89.7,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_catchtask_321()    //粗加工区回收物料321
{
  catch_back1();
  moveTo(cirle_dis, 2, 3500);  //回退2绿
  move_adjust(89.7, 100);      //陀螺仪校准
  catch_back2();
  moveTo(cirle_dis, 2, 3500);  //回退1红
  move_adjust(89.7, 100);          //陀螺仪校准
  catch_back3();
  moveTo(cirle_dis*2, 1, 3500);  //前进蓝色中心
  step3_change();  //校准圆心
  for (int i=0; i<133; i++)
  {
  base.write(i);
  delay(7);
  }
  move_adjust(89.7, 100);          //陀螺仪校准
  
}
void d123()
{
  step3_puttask_123();
  step3_catchtask_123();
}
void d132()
{
  step3_puttask_132();
  step3_catchtask_132();
}
void d213()
{
  step3_puttask_213();
  step3_catchtask_213();
}
void d231()
{
  step3_puttask_231();
  step3_catchtask_231();
}
void d321()
{
  step3_puttask_321();
  step3_catchtask_321();
}
void d312()
{
  step3_puttask_312();
  step3_catchtask_312();
}

void callStepFunctions(int code) {
    switch (code) {
        case 123:
            d123();
            break;
        case 132:
             d123();
            break;
        case 213:
            d213();
            break;
        case 231:
            d231();
            break;
        case 321:
            d321();
            break;
        case 312:
            d312();
            break;
        default:
            // Handle the case where the code doesn't match any of the above cases
            break;
    }
  

}

void use()
{
  sendInstruction(0x02);//识别物料
 // receiveAndProcessPacket();
  delay(500);
  sendInstruction(0x01);//识别色环
  //receiveAndProcessPacket();
  delay(500);
}