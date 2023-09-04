from scapy.all import IP, ICMP, srp1

import Additional_Functions as AF
USER_INPUT = input("Enter the Network Address : ")
Network_Address, Network_Bits = AF.Network_Tuple(USER_INPUT)
Network_ID = AF.Strfy(AF.Network_ID(Network_Address, Network_Bits))
Subnet_Mask = AF.Strfy(AF.Subnet_Generator(Network_Bits))
Broadcast_ID = AF.Strfy(AF.Broadcast_ID(Network_Address, Network_Bits))
Total_Hosts = AF.Total_Hosts(Network_Bits)
Generated_Host_Addresses = AF.Host_IP_Generator(Network_Address, Network_Bits)

print(Network_Address, Network_Bits)
print(Network_ID, Subnet_Mask, Broadcast_ID, Total_Hosts, Generated_Host_Addresses)

Alive_Hosts = set()
for Host in Generated_Host_Addresses:
    packet = srp1(IP(dst=Host)/ICMP()/"DUMMY", timeout = 0.5)
    if packet:
        Alive_Hosts.add(Host)

print(Alive_Hosts)
