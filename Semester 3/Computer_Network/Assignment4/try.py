from scapy.all import sniff

def packet_handler(packet):
    print(packet.summary())

# Sniff 10 packets
sniff(count=100, prn=packet_handler, filter="tcp")
