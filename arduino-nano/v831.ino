byte buf[10]; // 数据缓冲数组
int bufIndex = 0; // 缓冲区索引





bool isReceiving = false; // 用于跟踪数据包接收状态



void receiveAndProcessPacket() {
  while (Serial3.available() > 0) {
    byte receivedByte = Serial3.read();

    // 如果不在接收数据包中，检查是否收到包头 0x4A
    if (!isReceiving && receivedByte == 0x4A) {
      isReceiving = true;
      bufIndex = 0;
    }

    // 如果在接收数据包中，将数据添加到缓冲区
    if (isReceiving) {
      buf[bufIndex] = receivedByte;
      bufIndex++;

      // 如果已经接收到10个字节，检查包尾 0x4C
      if (bufIndex >= 10) {
        if (buf[9] == 0x4C) {
          // 提取并处理数据
          int data1 = (buf[2] * 100) + (buf[3] * 10) + buf[4];
          int data2 = (buf[5] * 100) + (buf[6] * 10) + buf[7];
          int data3 = buf[8];

          // 将数据存储在Data数组中
          Data[0] = data1;
          Data[1] = data2;
          Data[2] = data3;

            for(int i=0;i<3;i++){
              Serial.println(Data[i]);
            }
        } 
        // 重置数据包接收状态
        isReceiving = false;
      }
    }
  }
}

void sendInstruction(byte instruction) {
  byte packet[3];
  packet[0] = 0x3A; // 包头
  packet[1] = 0x3B; // 包头
  packet[2] = instruction; // 指令码，范围00-99

  // 发送数据包，包尾为0x3C
  Serial3.write(packet, 3);
  Serial3.write(0x3C); // 包尾

}

/*
void loop() {
  receiveAndProcessPacket();

  // 发送指令码，instruction可以根据需要更改
  byte instruction = 0x99; // 指令码，范围00-99
  sendInstruction(instruction);

  delay(1000); // 1秒的延时示例

}*/
