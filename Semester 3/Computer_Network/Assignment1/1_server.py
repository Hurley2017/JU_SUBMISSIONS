import socket
import datetime

# Define the TCP port and IP address to bind the server socket
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'

# Define the buffer size for receiving data
BUF_SIZE = 1024

# Response prefix
Reset = 'Hello Client with Address : '

# Create a server socket using IPv4 and TCP
Server_Socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the server socket to the specified IP address and port
Server_Socket.bind((IP_ADDR, TCP_PORT))

# Print server information
print("Server is running and will be listening on port ", TCP_PORT, " : ")

while True:
    # Start listening for incoming connections
    Server_Socket.listen(1)

    # Accept an incoming connection from a client
    Client_Socket, Client_Address = Server_Socket.accept()

    # Receive data from the client and decode it
    Incoming_Data = Client_Socket.recv(BUF_SIZE).decode()

    # Print received data and client address
    print("Server received data: '", Incoming_Data, "' from Client with Address : '", Client_Address, "'")

    # Check the received command and generate a reply
    if Incoming_Data == 'What is the time?':
        # Get the current date and time
        Current = str(datetime.datetime.now())
        time = Current.split(' ')[1].split('.')[0]
        date = Current.split(' ')[0]
        # Create a reply with the current time and date
        Reply = Reset + str(Client_Address) + '. The Time is: ' + time + ' on Date : ' + date
        # Send the reply back to the client after encoding
        Client_Socket.send(Reply.encode())
    else:
        # If the command is not recognized, send an "Unknown Command" reply
        Reply = Reset + str(Client_Address) + '. Unknown Command'
        Client_Socket.send(Reply.encode())
