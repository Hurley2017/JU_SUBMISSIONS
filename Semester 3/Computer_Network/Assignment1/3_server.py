import socket
import Additional_Functions as AF

LOCAL_IP = "127.0.0.1"
LOCAL_PORT = 20001
BUF_SIZE = 1024

Reset = 'Hello Client with Address : '
Server_Socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
Server_Socket.bind((LOCAL_IP, LOCAL_PORT))

print("Server is running and will be listening on port ", LOCAL_PORT, " : ")

while True:
    Collective_Info = AF.Read_File()
    Incoming_Packet = Server_Socket.recvfrom(BUF_SIZE)
    Client_Socket, Client_Address = Incoming_Packet[1]
    Incoming_Data = Incoming_Packet[0].decode()
    print("Server received data: '", Incoming_Data, "' from Client with Address : '", Client_Socket, "'")
    if Incoming_Data in Collective_Info:
        Server_Socket.sendto(Collective_Info[Incoming_Data].encode(), (Client_Socket, Client_Address))
    else:
        Server_Socket.sendto("Invalid Name".encode(), (Client_Socket, Client_Address))







