import sensor, image, time, pyb
from pyb import UART

# 初始化摄像头
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)

# 初始化串口连接
uart = UART(3, 115200)

# 帧头和帧尾
frame_header = bytes([0x5a, 0x5b])
frame_footer = bytes([0x5c])

while True:
    img = sensor.snapshot()  # 捕获图像

    # 查找二维码
    for code in img.find_qrcodes():
        payload = code.payload()  # 提取二维码的数据


        # 移除加号字符
        payload = payload.replace("+", "")
        #print(payload)

        # 确保字符串长度为6
        if len(payload) == 6:
            data_array = list(payload)  # 将提取后的6个字符转换为字节对象
            data_array = [int(char) for char in payload]

            data_packet = [0x5a, 0x5b] + data_array + [0x5c]
            # 构建数据包
            #data_packet = frame_header + data_array + frame_footer

            # 发送数据包到串口连接
            uart.write(bytes(data_packet))

            # 在图像上绘制二维码信息和框架
            img.draw_rectangle(code.rect(), color = (0, 255, 0))
            img.draw_string(code.rect()[0], code.rect()[1], payload, color = (255, 0, 0))
