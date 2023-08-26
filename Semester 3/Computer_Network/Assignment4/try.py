from scapy.all import sniff

DIST_HOST_ID = set()
DIST_PAIR = {}
TCP_COUNT = 0
UDP_COUNT = 0
ICMP_COUNT = 0




# Sniff 10000 packets
PACKETS = sniff(count=10000, filter="tcp or udp or icmp")
for PACKET in PACKETS:
    if PACKET.haslayer('TCP'):
        TCP_COUNT += 1        
    elif PACKET.haslayer('UDP'):
        UDP_COUNT += 1
    elif PACKET.haslayer('ICMP'):
        ICMP_COUNT += 1
    if PACKET['IP'].src not in DIST_HOST_ID:           
        DIST_HOST_ID.add(PACKET['IP'].src)
    if (PACKET['IP'].src , PACKET['IP'].dst) not in DIST_PAIR:
        DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)] = [1, [], 1, [], 1, [], 0, 0, 0]
    else:
        if PACKET.haslayer('TCP'):
            DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)][0] += 1
            DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)][1].append(len(PACKET['TCP'].payload))
        elif PACKET.haslayer('UDP'):
            DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)][2] += 1
            DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)][3].append(len(PACKET['UDP'].payload))
        elif PACKET.haslayer('ICMP'):
            DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)][4] += 1
            DIST_PAIR[(PACKET['IP'].src , PACKET['IP'].dst)][5].append(len(PACKET['ICMP'].payload))
for PAIR in DIST_PAIR:
    DIST_PAIR[PAIR][6] = sum(DIST_PAIR[PAIR][1])/DIST_PAIR[PAIR][0]
    DIST_PAIR[PAIR][7] = sum(DIST_PAIR[PAIR][1])/DIST_PAIR[PAIR][2]
    DIST_PAIR[PAIR][8] = sum(DIST_PAIR[PAIR][1])/DIST_PAIR[PAIR][4]

print('Total TCP Packets : ', TCP_COUNT)
print('Total UDP Packets : ', UDP_COUNT)
print('Total ICMP Packets : ', ICMP_COUNT)
print('Distinct Host Ips : ', DIST_HOST_ID)
print('The Table : ')
print('Source Ip | Destination Ip | Protocol | Number of Segments | Average Payload Length')
for PAIR in DIST_PAIR:
    print(PAIR[0], ' | ', PAIR[1], ' | ', 'TCP', ' | ', DIST_PAIR[PAIR][0], ' | ', DIST_PAIR[PAIR][6])
    print(PAIR[0], ' | ', PAIR[1], ' | ', 'UDP', ' | ', DIST_PAIR[PAIR][2], ' | ', DIST_PAIR[PAIR][7])
    print(PAIR[0], ' | ', PAIR[1], ' | ', 'ICMP', ' | ', DIST_PAIR[PAIR][4], ' | ', DIST_PAIR[PAIR][8])


