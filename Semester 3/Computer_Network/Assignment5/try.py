# from scapy.all import IP, ICMP, srp


# def ping(ip, to):
#     packet = IP(dst=ip) / ICMP()
#     resp = srp(packet, timeout=to, verbose=False)[0]
#     print(resp)

# ping('192.168.0.2', 1)