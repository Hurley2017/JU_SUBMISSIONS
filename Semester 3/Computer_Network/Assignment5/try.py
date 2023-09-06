from scapy.all import IP, TCP, ICMP, srp, sr1, send, sendp, srloop


def ping(ip, to):
    packet = IP(dst=ip) / ICMP() / "Hello"
    receive = srloop(packet, count=to, timeout=1)[0]
    print(receive)
    if len(receive) == 0:
        return False
    elif receive[0][1]['ICMP'].type == 0:
        return True
    else:
        return False
ping('192.168.0.104', 1)