import socket
import datetime

TCP_PORT = 5000
IP_ADDR = '127.0.0.1'
BUF_SIZE = 1024
Reset = 'Hello Client with Address : '
Server_Socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
Server_Socket.bind((IP_ADDR, TCP_PORT))

print("Server is running and will be listening on port 5000 : ")

while True:
    Server_Socket.listen(1)
    Client_Socket, Client_Address = Server_Socket.accept()
    Incoming_Data = Client_Socket.recv(BUF_SIZE).decode()
    print("Server received data: '", Incoming_Data, "' from Client with Address : '", Client_Address, "'")
    if Incoming_Data == 'What is the time?':
        Current = str(datetime.datetime.now())
        time = Current.split(' ')[1].split('.')[0]
        date = Current.split(' ')[0]
        Reply = Reset + str(Client_Address) + '. The Time is: ' + time + ' on Date : ' + date
        Client_Socket.send(Reply.encode())
    else:
        Reply = Reset + str(Client_Address) + '. Unknown Command'
        Client_Socket.send(Reply.encode())





