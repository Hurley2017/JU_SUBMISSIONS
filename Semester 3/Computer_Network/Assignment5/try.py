from scapy.all import IP, ICMP, sr1

import sys, os

def blockPrint():
    sys.stdout = open(os.devnull, 'w')

def enablePrint():
    sys.stdout = sys.__stdout__

def ping(ip, to):
    print(to)
    icmp = IP(dst=ip)/ICMP()/"DUMMY"
    # blockPrint()
    resp = sr1(icmp, timeout=to)
    # enablePrint()
    if resp != None:
        resp.show()
        print(resp.summary())

ping('192.168.0.190', 1)