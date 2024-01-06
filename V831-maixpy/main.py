#####指令01,02可用
#23-10-13-23-01更改
from pickle import NONE
from maix import image, camera, display
import serial, struct, time, struct

ser = serial.Serial("/dev/ttyS1", 57600,timeout = 0.03)

hex_chars = []
code = '00'


def detect_circles_and_colors(img):
    
    detected_circles = []
    
    red_thresh = [(16, 62, 19, 82, -24, 82)]
    green_thresh = [(25, 72, -43, -7, -8, 40)]
    blue_thresh = [(0, 47, 0, 36, -52, -16)]
    
    red_blobs = img.find_blobs(red_thresh, merge=True)
    green_blobs = img.find_blobs(green_thresh, merge=True)
    blue_blobs = img.find_blobs(blue_thresh, merge=True)

    circles = img.find_circles(
        threshold=3500,  # 阈值，用于检测圆形
        x_margin=2,     # x轴误差允许值
        y_margin=2,     # y轴误差允许值
        r_margin=2,      # 半径误差允许值
        r_min=35,        # 最小半径
        r_max=37,        # 最大半径
        r_step=1         # 半径步进值
    )

    if circles:

        for c in circles:
            center_x, center_y = c[0], c[1]
            closest_color = None
            closest_distance = float('inf')  # 初始设为正无穷大

            # 寻找最接近的颜色块
            for color_blobs in [red_blobs, green_blobs, blue_blobs]:
                if color_blobs:
                    for blob in color_blobs:
                        blob_center_x = blob['x'] + blob['w'] // 2
                        blob_center_y = blob['y'] + blob['h'] // 2
                        distance = (center_x - blob_center_x)**2 + (center_y - blob_center_y)**2

                        if distance < closest_distance:
                            closest_color = color_blobs
                            closest_distance = distance

            if closest_color:
                # 设置绘制颜色
                if closest_color == red_blobs:
                    color = 1  # 红色
                elif closest_color == green_blobs:
                    color = 2  # 绿色
                elif closest_color == blue_blobs:
                    color = 3  # 蓝色

                detected_circles.append((center_x, center_y, color))

    return detected_circles

def color_area(img):
    detected_color_areas = []  # 创建一个空列表来存储检测到的颜色区域信息

    x_center = 0
    y_center = 0
    color_name = 0

    set_LAB = [
        [(0, 65, 42, 94, -40, 70)],  # red
        [(0, 61, -24, 53, -88, -27)],  # blue
        [(7, 75, -111, -27, -35, 121)]  # green
    ]
    
    for j in range(3):
        blobs = img.find_blobs(set_LAB[j])
        if blobs:
            for i in blobs:
                size = i["w"] * i["h"]
                if size > 3000:
                    x_start = i["x"]
                    x_end = i["x"] + i["w"]
                    x_center = int((x_start + x_end) / 2)
                    y_start = i["y"]
                    y_end = i["y"] + i["h"]
                    y_center = int((y_start + y_end) / 2)
                    
                    # 计算中心点的坐标
                    m = max((x_center - i["w"] * 0.3), 0)
                    n = max((y_center - i["h"] * 0.3), 0)
                    m = min((x_center - i["w"] * 0.3), 240)
                    n = min((y_center - i["h"] * 0.3), 240)
                    mk = [int(m), int(n), 20, 20]

                    if (mk[0] + 20) < 220 and (mk[1] + 20) < 220:
                        git_color = img.get_blob_color(mk, 0, 0)
                        #color = (int(git_color[0]), int(git_color[1]), int(git_color[2]))

                        if j == 0:
                            color_name = 1
                        elif j == 1:
                            color_name = 3
                        elif j == 2:
                            color_name = 2

                        # 将检测到的颜色区域信息添加到列表中
                        detected_color_areas.append((x_center, y_center, color_name))

    return detected_color_areas


def send_data_packet(data):
    for x, y, color in data:
        data_packet = bytes([0x4A, 0x4B, x // 100, (x // 10) % 10, x % 10, y // 100, (y // 10) % 10, y % 10, color, 0x4C])
        ser.write(data_packet)


while True:

    img = camera.capture()

    if ser.in_waiting > 0:  
        data = ser.read(4)
        hex_chars = []
        for byte in data:
            hex_chars.append('%02x' % byte)
        #print(hex_chars)
        if hex_chars[0] == '3a' and hex_chars[1] == '3b' and hex_chars[3] == '3c':
            code = hex_chars[2]
            #print(code)
        data = b''

    if code == '00':
        pass

    elif code == '01':
        #print('01!')
        result = detect_circles_and_colors(img)
    
        if result:
            send_data_packet(result)
            for x, y, color in result:
                img.draw_circle(x, y, 5, (255, 255, 0), -1)
        code = '00'

    if code == '02':
        result = color_area(img)
        #print('02!')

        if result:
            send_data_packet(result)
            for x, y, color in result:
                img.draw_circle(x, y, 5, (255, 255, 0), -1)
        code = '00'
    
    
    img.draw_circle(135,105,10,(255,0,0), -1)
    display.show(img)
