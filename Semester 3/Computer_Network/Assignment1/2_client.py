import socket

# Define the TCP port and IP address to connect to
TCP_PORT = 5000
IP_ADDR = '127.0.0.1'

# Define the buffer size for receiving data
BUF_SIZE = 1024

while True:
    # Create a new client socket using IPv4 and TCP
    Client_Socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect the client socket to the server
    Client_Socket.connect((IP_ADDR, TCP_PORT))

    # Prompt the user to enter an expression
    Command = input('Enter an Expression: ')

    # Send the entered expression to the server after encoding it
    Client_Socket.send(Command.encode())

    # Receive the server's reply and decode it
    Reply = Client_Socket.recv(BUF_SIZE).decode()

    # Print the server's reply
    print("Server replied: '", Reply, "'")

    # Note: This loop runs indefinitely, allowing the client to repeatedly
    # connect to the server, send an expression, receive a reply, and display it.
    # To stop the client, you may need to manually terminate the program.
