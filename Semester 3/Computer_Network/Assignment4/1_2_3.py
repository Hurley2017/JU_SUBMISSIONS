from scapy.all import sniff
NUMBER_COUNT = int(input('How many packets to capture?')) 
print('Question 1 : ')
CAPTURED_Packets = sniff(count = NUMBER_COUNT, filter = 'tcp or udp or icmp')
for Packet in CAPTURED_Packets:
    print(Packet.summary())
    
print('\n\nQuestion 2 : ')
Distinct_Hosts = set()
for Packets in CAPTURED_Packets:
    try:
        if Packets['IP'].src not in Distinct_Hosts:
            Distinct_Hosts.add(Packets['IP'].src)
    except:
        pass
print('COUNT OF DISTINCT HOSTS : ', len(Distinct_Hosts))
print('THEY ARE ', Distinct_Hosts)

print('\n\nQuestion 3 : ')
Distinct_Pair = {}
for Packet in CAPTURED_Packets:
    try:
        if (Packet['IP'].src , Packet['IP'].dst) not in Distinct_Pair:
            Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)] = [1, [], 1, [], 1, [], 0, 0, 0]
        else:
            if Packet.haslayer('TCP'):
                Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)][0] += 1
                Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)][1].append(len(Packet['TCP'].payload))
            elif Packet.haslayer('UDP'):
                Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)][2] += 1
                Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)][3].append(len(Packet['UDP'].payload))
            elif Packet.haslayer('ICMP'):
                Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)][4] += 1
                Distinct_Pair[(Packet['IP'].src , Packet['IP'].dst)][5].append(len(Packet['ICMP'].payload))
    except:
        pass
for Pair in Distinct_Pair:
    Distinct_Pair[Pair][6] = sum(Distinct_Pair[Pair][1])/Distinct_Pair[Pair][0]
    Distinct_Pair[Pair][7] = sum(Distinct_Pair[Pair][1])/Distinct_Pair[Pair][2]
    Distinct_Pair[Pair][8] = sum(Distinct_Pair[Pair][1])/Distinct_Pair[Pair][4]
print('The Table : ')
print('Source Ip | Destination Ip | Protocol | Number of Segments | Average Payload Length')
for PAIR in Distinct_Pair:
    print(PAIR[0], ' | ', PAIR[1], ' | ', 'TCP', ' | ', Distinct_Pair[PAIR][0], ' | ', Distinct_Pair[PAIR][6])
    print(PAIR[0], ' | ', PAIR[1], ' | ', 'UDP', ' | ', Distinct_Pair[PAIR][2], ' | ', Distinct_Pair[PAIR][7])
    print(PAIR[0], ' | ', PAIR[1], ' | ', 'ICMP', ' | ', Distinct_Pair[PAIR][4], ' | ', Distinct_Pair[PAIR][8])

