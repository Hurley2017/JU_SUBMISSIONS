# Import necessary modules
from scapy.all import IP, TCP
from time import sleep
import threading
import Additional_Functions as AF

# Create an empty set to store alive ports
Alive_Ports = set()

# Get user input for the network address to scan
USER_INPUT = input("Enter the Network Address : ")

# Initialize variables for port range
i, j = 0, 100

# Define a function to perform port scanning within a range
def Process(i, j):
    for i in range(i, j):
        # Call a function from Additional_Functions to send TCP packets and check if a port is alive
        AF.TCP_SEND(USER_INPUT, i, Alive_Ports)

# Perform port scanning in multiple threads
while i < 1024 and j < 1024:
    # Start a new thread for port scanning within the range [i, j)
    threading.Thread(target=Process, args=(i, j)).start()
    
    # Update the range for the next thread
    i += 100
    if j + 100 > 1024:
        j = 1024
    else:
        j += 100

# Sleep for 15 seconds to allow threads to finish scanning
sleep(15)

# Print the total alive ports after scanning is complete
print("Total Alive Ports : ")
print(Alive_Ports)