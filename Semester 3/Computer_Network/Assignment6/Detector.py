from scapy.all import sniff
import os

# Dictionary to hold IP to MAC address mappings
ARP_TABLE = {}

# Run 'arp -a' command to get ARP table information
output = os.popen('arp -a').read()
output = output.split('\n')
output = output[3:-1]

# Parse the output and populate the ARP_TABLE dictionary
for line in output:
    line = line.split()
    ARP_TABLE[line[0]] = line[1].replace('-', ':')

print(ARP_TABLE)

# Print headers for output
print('Source', '\t', 'HW_Source', '\t', 'Status')

# Function to detect ARP spoofing
def detect(packet):
    Source = packet['ARP'].psrc
    HW_Source = packet['ARP'].hwsrc
    
    # Check if the source IP is in the ARP_TABLE
    if Source in ARP_TABLE:
        # If the MAC address for the IP has changed, it might indicate ARP spoofing
        if ARP_TABLE[Source] != HW_Source:
            print(Source, HW_Source, 'ARP Spoofing Detected')
        else:
            print(Source, HW_Source, 'Seems Legit')
    else:
        # If a new device is detected, add it to the ARP_TABLE
        print(Source, HW_Source, 'New Device Detected')
        ARP_TABLE[Source] = HW_Source

# Continuously sniff ARP packets and call the detect function
while True:
    sniff(prn=detect, filter='arp', count=1)
