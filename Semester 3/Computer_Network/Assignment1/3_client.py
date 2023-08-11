import socket

LOCAL_IP = '127.0.0.1'
LOCAL_PORT = 20001
BUF_SIZE = 1024

Server_Socket_Address = (LOCAL_IP, LOCAL_PORT)

while True:
    Client_Socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    MyName = input("Enter Name : ")
    MyName = MyName.encode()
    Client_Socket.sendto(MyName, Server_Socket_Address)
    Incoming_Packet = Client_Socket.recvfrom(BUF_SIZE)
    Incoming_Data = Incoming_Packet[0].decode()
    print("Server sent Address: '", Incoming_Data, "'")