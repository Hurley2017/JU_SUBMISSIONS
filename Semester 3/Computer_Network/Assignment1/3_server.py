import socket
import Additional_Functions as AF  # Assuming this module contains necessary functions

# Define local IP address and port for the server socket
LOCAL_IP = "127.0.0.1"
LOCAL_PORT = 20001

# Define the buffer size for receiving data
BUF_SIZE = 1024

# Response prefix
Reset = 'Hello Client with Address : '

# Create a server socket using UDP
Server_Socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the server socket to the specified local IP address and port
Server_Socket.bind((LOCAL_IP, LOCAL_PORT))

# Print server information
print("Server is running and will be listening on port ", LOCAL_PORT, " : ")

while True:
    # Read collective information from a file using the Additional_Functions module
    Collective_Info = AF.Read_File()

    # Receive incoming packet from the client
    Incoming_Packet = Server_Socket.recvfrom(BUF_SIZE)
    Incoming_Data, Client_Address = Incoming_Packet

    # Decode the received data and print client information
    Incoming_Data = Incoming_Data.decode()
    print("Server received data: '", Incoming_Data, "' from Client with Address : '", Client_Address, "'")

    if Incoming_Data in Collective_Info:
        # If the incoming data (name) is in the collective info, send the corresponding info back
        Info = Collective_Info[Incoming_Data]
        Server_Socket.sendto(Info.encode(), Client_Address)
    else:
        # If the name is not found, send an "Invalid Name" reply
        Server_Socket.sendto("Invalid Name".encode(), Client_Address)
