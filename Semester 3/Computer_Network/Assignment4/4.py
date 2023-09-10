# Import the necessary module from Scapy for packet sniffing
from scapy.all import sniff

# Ask the user for the number of packets to capture
NUMBER_COUNT = int(input('How many packets to capture?'))

# Use Scapy's sniff function to capture packets based on the specified count and filter
CAPTURED_Packets = sniff(count=NUMBER_COUNT, filter='tcp or udp or icmp')

# Define a dictionary that maps IP protocol numbers to protocol names
Proto_Dictionary = {
    6: 'TCP',
    17: 'UDP',
    1: 'ICMP'
}

# Print a message for Question 4
print('\n\nQuestion 4 : ')

# Create a dictionary to store information about distinct pairs of source IP, source port, destination IP, destination port, and protocol
Distinct_Pair = {}

# Iterate through captured packets and try to extract relevant information
for Packet in CAPTURED_Packets:
    try:
        Current_IP_src = Packet['IP'].src
        Current_IP_dst = Packet['IP'].dst
        Current_IP_proto = Proto_Dictionary[Packet['IP'].proto]
        Current_IP_sport = Packet[Current_IP_proto].sport
        Current_IP_dport = Packet[Current_IP_proto].dport
        
        # Check if the 5-tuple (source IP, source port, destination IP, destination port, protocol) is already in the dictionary; if not, add it
        if (Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport, Current_IP_proto) not in Distinct_Pair:
            Distinct_Pair[(Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport, Current_IP_proto)] = [1, [len(Packet[Current_IP_proto].payload)], 0]
        else:
            # Update the count and payload length list for the existing 5-tuple
            Distinct_Pair[(Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport, Current_IP_proto)][0] += 1
            Distinct_Pair[(Current_IP_src, Current_IP_sport, Current_IP_dst, Current_IP_dport, Current_IP_proto)][1].append(len(Packet[Current_IP_proto].payload))
    except:
        pass

# Calculate the average payload length for each distinct 5-tuple
for Pair in Distinct_Pair:
    Distinct_Pair[Pair][2] = sum(Distinct_Pair[Pair][1]) / Distinct_Pair[Pair][0]

# Print a table header
print("The Table : ")
print("Source IP | Destination IP | Protocol | Source Port | Destination Port | Number of Segments | Average Payload Length")

# Iterate through distinct 5-tuples and print their information
for Data in Distinct_Pair:
    print(Data[0],'|', Data[2],'|', Data[4],'|', Data[1],'|', Data[3],'|', Distinct_Pair[Data][0],'|', Distinct_Pair[Data][2])
