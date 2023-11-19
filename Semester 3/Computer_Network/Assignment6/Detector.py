from scapy.all import sniff
import os

ARP_TABLE = {}

#run arp -a and capture the output
Output = os.popen('arp -a').read()
Output = Output.split('\n')
Output = Output[3:-1]
for line in Output:
    line = line.split()
    ARP_TABLE[line[0]] = line[1].replace('-',':')

print(ARP_TABLE)


print('Source','\t', 'HW_Source','\t', 'Status')

def detect(packet):
    Source = packet['ARP'].psrc
    HW_Source = packet['ARP'].hwsrc
    if Source in ARP_TABLE:
        if ARP_TABLE[Source] != HW_Source:
            print(Source, HW_Source,'ARP Spoofing Detected')
        else:
            print(Source, HW_Source,'Seems Legit')
    else:
        print(Source, HW_Source,'New Device Detected')
        ARP_TABLE[Source] = HW_Source




while True: 
    sniff(prn=detect, filter='arp', count=1)