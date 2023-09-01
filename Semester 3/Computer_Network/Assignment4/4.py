from scapy.all import sniff
NUMBER_COUNT = int(input('How many packets to capture?')) 
CAPTURED_Packets = sniff(count = NUMBER_COUNT, filter = 'tcp or udp or icmp')
#print the ports of the captured packets of scapy
Proto_Dictionary = {
    6 : 'TCP',
    17: 'UDP',
    1 : 'ICMP'
}

# for packet in CAPTURED_Packets:
#     print(packet.summary())
print('\n\nQuestion 4 : ')
Distinct_Pair = {}
for Packet in CAPTURED_Packets:
    try:
        Current_IP_src = Packet['IP'].src
        Current_IP_dst = Packet['IP'].dst
        Current_IP_proto = Proto_Dictionary[Packet['IP'].proto]
        Current_IP_sport = Packet[Current_IP_proto].sport
        Current_IP_dport = Packet[Current_IP_proto].dport
        if (Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport) not in Distinct_Pair:
            Distinct_Pair[(Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport)] = [Current_IP_proto, 1, [len(Packet[Current_IP_proto].payload)], 0]
        else:
            Distinct_Pair[(Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport)][1] += 1
            Distinct_Pair[(Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport)][2].append(len(Packet[Current_IP_proto].payload))
    except:
        pass

# print(Distinct_Pair)

for Pair in Distinct_Pair:
    Distinct_Pair[Pair][3] = sum(Distinct_Pair[Pair][2])/Distinct_Pair[Pair][1]

print("The Table : ")
print("Source IP | Destination IP | Protocol | Source Port | Destination Port | Number of Segments | Average Payload Length")
for Data in Distinct_Pair:
    print(Data[0],'|', Data[2],'|', Distinct_Pair[Data][0],'|', Data[1],'|', Data[3],'|', Distinct_Pair[Data][1],'|', Distinct_Pair[Data][3])


