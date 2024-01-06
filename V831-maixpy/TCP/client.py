import socket

# 创建TCP socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接广播主机的IP和端口
client.connect(('192.168.184.15', 12345)) 

while True:
    # 接收数据
    data = client.recv(1024)
    
    if not data:
        break
    
    # 打印接收到的数据
    print(data.decode('utf-8'))

client.close()
