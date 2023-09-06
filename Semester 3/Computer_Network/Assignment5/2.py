from scapy.all import IP, TCP, sr1
from time import sleep
import threading
import Additional_Functions as AF

Alive_Hosts = set()



USER_INPUT = input("Enter the Network Address : ")

for i in range(1024):
    threading.Thread(target=AF.TCP_SEND, args=(USER_INPUT, i, Alive_Hosts)).start()
    if i == 450 or i == 900:
        sleep(20)
sleep(20)
print("Total Alive Ports : ")
print(Alive_Hosts)