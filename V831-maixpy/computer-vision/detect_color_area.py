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
