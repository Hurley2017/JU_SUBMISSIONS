import socket

# Define local IP address and port to communicate with the server
LOCAL_IP = '127.0.0.1'
LOCAL_PORT = 20001

# Define the buffer size for receiving data
BUF_SIZE = 1024

# Create a tuple representing the server socket address
Server_Socket_Address = (LOCAL_IP, LOCAL_PORT)

while True:
    # Create a new client socket using UDP
    Client_Socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

    # Prompt the user to enter a name
    MyName = input("Enter Name : ")

    # Encode the name to bytes and send it to the server socket address
    MyName = MyName.encode()
    Client_Socket.sendto(MyName, Server_Socket_Address)

    # Receive incoming data from the server
    Incoming_Packet = Client_Socket.recvfrom(BUF_SIZE)
    Incoming_Data = Incoming_Packet[0].decode()

    # Print the server's sent address
    print("Server sent Address: '", Incoming_Data, "'")

# Note: This loop runs indefinitely, allowing the client to repeatedly
# send a name to the server, receive an address, and display it.
# To stop the client, you may need to manually terminate the program.
