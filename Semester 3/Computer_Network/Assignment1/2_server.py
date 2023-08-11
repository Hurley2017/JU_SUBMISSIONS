import socket
import Additional_Functions as AF  # Assuming this module contains necessary functions

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

    try:
        # Attempt to tokenize and convert the incoming arithmetic expression to postfix
        Incoming_Data = AF.Tokenizing_Operands(Incoming_Data)
        Incoming_Data = AF.Arithmetic_Expression_to_PostFix(Incoming_Data)
    except:
        # Handle any exceptions (e.g., invalid expression)
        Incoming_Data = 'Invalid Expression'

    if Incoming_Data != 'Invalid Expression':
        # Evaluate the postfix expression and generate a reply
        Result = AF.PostFix_Expression_Evaluation(Incoming_Data)
        Reply = Reset + str(Client_Address) + '. The Result is: ' + str(Result)
        # Send the reply back to the client after encoding
        Client_Socket.send(Reply.encode())
    else:
        # Send an "Invalid Expression" reply if necessary
        Reply = Reset + str(Client_Address) + '. Invalid Expression!'
        Client_Socket.send(Reply.encode())
