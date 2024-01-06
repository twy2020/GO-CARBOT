def send_data_packet(data):
    for x, y, color in data:
        data_packet = bytes([0x4A, 0x4B, x // 100, (x // 10) % 10, x % 10, y // 100, (y // 10) % 10, y % 10, color, 0x4C])
        ser.write(data_packet)
