from maix import image, camera, display
import serial

# 通过导入新的功能文件，将功能模块化
from detect_circles_colors import detect_circles_and_colors
from send_data_packet import send_data_packet
from detect_color_area import color_area

# 初始化串口
ser = serial.Serial("/dev/ttyS1", 57600, timeout=0.03)

# 主循环
while True:
    img = camera.capture()

    if ser.in_waiting > 0:
        data = ser.read(4)
        hex_chars = ['%02x' % byte for byte in data]
        
        if hex_chars[0] == '3a' and hex_chars[1] == '3b' and hex_chars[3] == '3c':
            code = hex_chars[2]

        data = b''

    if code == '00':
        pass

    elif code == '01':
        result = detect_circles_and_colors(img)

        if result:
            send_data_packet(result)
            for x, y, color in result:
                img.draw_circle(x, y, 5, (255, 255, 0), -1)
        code = '00'

    elif code == '02':
        result = color_area(img)

        if result:
            send_data_packet(result)
            for x, y, color in result:
                img.draw_circle(x, y, 5, (255, 255, 0), -1)
        code = '00'

    img.draw_circle(135, 105, 10, (255, 0, 0), -1)
    display.show(img)
