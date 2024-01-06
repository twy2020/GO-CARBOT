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
