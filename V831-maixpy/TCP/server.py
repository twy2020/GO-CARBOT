//GPT补生成，未改参数和测试
import socket

# 服务器配置
SERVER_IP = "0.0.0.0"  # 监听所有网络接口
SERVER_PORT = 12345  # 服务器端口号
BUFFER_SIZE = 1024

# 创建一个 TCP 套接字
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 将套接字绑定到服务器 IP 地址和端口号
server.bind((SERVER_IP, SERVER_PORT))

# 设置服务器套接字为监听状态，最大连接数为1
server.listen(1)

print(f"等待客户端连接在 {SERVER_IP}:{SERVER_PORT}")

# 接受客户端连接
client_socket, client_address = server.accept()
print(f"连接来自 {client_address}")

while True:
    try:
        # 从客户端接收数据
        data = client_socket.recv(BUFFER_SIZE)
        
        if not data:
            break
        
        # 打印接收到的数据
        print(f"收到来自客户端的数据: {data.decode('utf-8')}")

        # 从服务器端输入数据，并发送给客户端
        server_msg = input("输入要发送给客户端的数据: ")
        client_socket.send(server_msg.encode('utf-8'))

    except KeyboardInterrupt:
        print("服务器被中断")
        break

# 关闭连接
client_socket.close()
server.close()
