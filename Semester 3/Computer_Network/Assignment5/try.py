from scapy.all import IP, TCP, ICMP, srp, sr1, send, sendp, srloop
from time import sleep
import threading

Alive_Hosts = set()

def TCP_SEND(Host, Port):
    Packet = IP(dst=Host)/TCP(dport=Port, flags="S")
    Response = sr1(Packet, timeout=1)
    if Response != None and Response['TCP'].flags == "SA":
        print(Response['TCP'].flags)
        Alive_Hosts.add((Host, Port))


for i in range(1024):
    threading.Thread(target=TCP_SEND, args=("192.168.0.1", i)).start()
    if i == 450 or i == 900:
        sleep(20)
sleep(20)
print(Alive_Hosts)