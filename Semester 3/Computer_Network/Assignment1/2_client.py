import socket

TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024

while True:
    Client_Socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    Client_Socket.connect((IP_ADDR, TCP_PORT))
    Command = input('Enter a Expression: ')
    Client_Socket.send(Command.encode())
    Reply = Client_Socket.recv(BUF_SIZE).decode()
    print("Server replied: '", Reply, "'")