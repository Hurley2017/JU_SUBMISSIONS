from scapy.all import sr1, ICMP, IP

def traceroute(URL, MAX_HOPS):
    SUCCESS = False
    for TTL in range(1, MAX_HOPS+1):
        Packet = IP(dst=URL, ttl=TTL)/ICMP()/'Hello World'
        Reply = sr1(Packet, verbose=False, timeout=1)
        if Reply is None:
            print('TTL: ', TTL, ' * * *')
        elif Reply.type == 0:
            print('TTL: ', TTL, ' ', Reply.src)
            print('Reached Destination')
            SUCCESS = True
            break
        else:
            print('TTL: ', TTL, ' ', Reply.src)
    if not SUCCESS:
        print('Destination Unreachable')

URL = input('Enter URL: ')
MAX_HOPS = int(input('Enter Max Hops: '))
traceroute(URL, MAX_HOPS)