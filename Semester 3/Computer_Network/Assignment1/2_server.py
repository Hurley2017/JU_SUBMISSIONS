import socket
import Additional_Functions as AF
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
    try:
        Incoming_Data = AF.Tokenizing_Operands(Incoming_Data)
        Incoming_Data = AF.Arithmatic_Expression_to_PostFix(Incoming_Data)
    except:
        Incoming_Data = 'Invalid Expression'
    if Incoming_Data != 'Invalid Expression':
        Result = AF.PostFix_Expression_Evaluation(Incoming_Data)
        Reply = Reset + str(Client_Address) + '. The Result is: ' + str(Result)
        Client_Socket.send(Reply.encode())
    else:
        Reply = Reset + str(Client_Address) + '. Invalid Expression!'
        Client_Socket.send(Reply.encode())





