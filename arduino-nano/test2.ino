
void step3_puttask_213_1()    //粗加工区放置物料213
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
    move_adjust(89.7*2,100);   //陀螺仪校准
    moveTo(cirle_dis, 2, 3500);  //回退1红
    move_adjust(89.7*2,100);               //陀螺仪校准
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
      move_adjust(89.7*2,100);                   //陀螺仪校准
      moveTo(cirle_dis * 2, 1, 3500);  //前进3蓝
      move_adjust(89.7*2,100);                   //陀螺仪校准
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
        move_adjust(89.7*2,100);   //陀螺仪校准 
        moveTo(cirle_dis , 2, 3500);  //回到绿色中心
        step3_change();                  //校准圆心        
        move_adjust(89.7*2,100);        //陀螺仪校准
      }
    }
  }
}
void step3_puttask_231_1()    //粗加工区放置物料231
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
    move_adjust(89.7*2,100);   //陀螺仪校准
    moveTo(cirle_dis, 1, 3500);  //前进3蓝
    move_adjust(89.7*2,100);               //陀螺仪校准
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
      move_adjust(89.7*2,100);                   //陀螺仪校准
      moveTo(cirle_dis * 2, 2, 3500);  //回退1红
      move_adjust(89.7*2,100);                   //陀螺仪校准
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
        move_adjust(89.7*2,100);   //陀螺仪校准 
        moveTo(cirle_dis,1,3500);   //前往绿色中心
        step3_change();                  //校准圆心
        move_adjust(89.7*2,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_puttask_123_1()    //粗加工区放置物料123
{
  moveTo(cirle_dis, 2, 3500);
  stillness_1();
  while(QR_code[0] != Data[2])
  {
    stillness_1();
  }
  if (QR_code[0] == Data[2])  //123 红 绿 蓝
  {  
    step3_change();  //校准圆心
    catch_disk21();   //1红 执行放置
    arm.moveTo(-655);   //抬起机械臂
    arm.runToPosition();
    delay(50);
    move_adjust(89.7*2,100);   //陀螺仪校准
    moveTo(cirle_dis, 1, 3500);  //前进2绿
    move_adjust(89.7*2,100);               //陀螺仪校准
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
      move_adjust(89.7*2,100);                   //陀螺仪校准
      moveTo(cirle_dis, 1, 3500);  //前进3蓝
      move_adjust(89.7*2,100);                   //陀螺仪校准
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
        move_adjust(89.7*2,100);   //陀螺仪校准 
        moveTo(cirle_dis ,2,3500);   //回到绿色中心
        step3_change();                  //校准圆心
        move_adjust(89.7*2,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_puttask_132_1()    //粗加工区放置物料132///////////////////////////////
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
    move_adjust(89.7*2,100);   //陀螺仪校准
    moveTo(cirle_dis*2, 1, 3500);  //前进3蓝
    move_adjust(89.7*2,100);               //陀螺仪校准
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
      move_adjust(89.7*2,100);                   //陀螺仪校准
      moveTo(cirle_dis, 2, 3500);  //前进2绿
      move_adjust(89.7*2,100);                   //陀螺仪校准
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
        step3_change();  //校准圆心
        move_adjust(89.7*2,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_puttask_312_1()    //粗加工区放置物料312
{
  moveTo(cirle_dis, 1, 3500);
  step3_change();  //校准圆心
  move_adjust(89.7*2, 100);//陀螺仪校准
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
    move_adjust(89.7*2,100);   //陀螺仪校准
    moveTo(cirle_dis * 2, 2, 3500);  //回退1红
    move_adjust(89.7*2,100);               //陀螺仪校准
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
      move_adjust(89.7*2,100);                   //陀螺仪校准
      moveTo(cirle_dis , 1, 3500);  //前进2绿
      move_adjust(89.7*2,100);                   //陀螺仪校准
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
        step3_change();  //校准圆心
        move_adjust(89.7*2,100);   //陀螺仪校准 
      }
    }
  }
}
void step3_puttask_321_1()    //粗加工区放置物料321
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
    move_adjust(89.7*2,100);   //陀螺仪校准
    moveTo(cirle_dis, 2, 3500);  //回退2绿
    move_adjust(89.7*2,100);               //陀螺仪校准
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
      move_adjust(89.7*2,100);                   //陀螺仪校准
      moveTo(cirle_dis , 2, 3500);  //回退1红
      move_adjust(89.7*2,100);                   //陀螺仪校准
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
        move_adjust(89.7*2,100);   //陀螺仪校准 
        moveTo(cirle_dis,1,3500);   //回到绿色中心
        step3_change();  //校准圆心
        move_adjust(89.7*2,100);   //陀螺仪校准 
      }
    }
  }
}
void d123_1()
{
  step3_puttask_123_1();
}
void d132_1()
{
  step3_puttask_132_1();
}
void d213_1()
{
  step3_puttask_213_1();
}
void d231_1()
{
  step3_puttask_231_1();
}
void d321_1()
{
  step3_puttask_321_1();
}
void d312_1()
{
  step3_puttask_312_1();
}

void callStepFunctions_1(int code) {
    switch (code) {
        case 123:
            d123_1();
            break;
        case 132:
             d123_1();
            break;
        case 213:
            d213_1();
            break;
        case 231:
            d231_1();
            break;
        case 321:
            d321_1();
            break;
        case 312:
            d312_1();
            break;
        default:
            // Handle the case where the code doesn't match any of the above cases
            break;
    }
  

}


