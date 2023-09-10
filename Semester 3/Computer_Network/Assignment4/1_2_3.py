# Import the necessary module from Scapy for packet sniffing
from scapy.all import sniff

# Ask the user for the number of packets to capture
NUMBER_COUNT = int(input('How many packets to capture?'))

# Use Scapy's sniff function to capture packets based on the specified count and filter
CAPTURED_Packets = sniff(count=NUMBER_COUNT, filter='tcp or udp or icmp')

# Commented out code that prints a summary of captured packets

# Create an empty set to store distinct source IP addresses
Distinct_Hosts = set()

# Iterate through captured packets and try to extract the source IP address because ARP packets may exist.
for Packets in CAPTURED_Packets:
    try:
        if Packets['IP'].src not in Distinct_Hosts:
            Distinct_Hosts.add(Packets['IP'].src)
    except:
        pass

# Print the count of distinct source IP addresses and the IP addresses themselves
print('COUNT OF DISTINCT HOSTS : ', len(Distinct_Hosts))
print('THEY ARE ', Distinct_Hosts)



# Define a dictionary that maps IP protocol numbers to protocol names
Proto_Dictionary = {
    6: 'TCP',
    17: 'UDP',
    1: 'ICMP'
}

# Create a dictionary to store information about distinct pairs of source IP, destination IP, and protocol
Distinct_Pair = {}

# Iterate through captured packets and try to extract relevant information
for Packet in CAPTURED_Packets:
    try:
        Current_IP_src = Packet['IP'].src
        Current_IP_dst = Packet['IP'].dst
        Current_IP_proto = Proto_Dictionary[Packet['IP'].proto]
        
        # Check if the pair is already in the dictionary; if not, add it
        if (Current_IP_src, Current_IP_dst, Current_IP_proto) not in Distinct_Pair:
            Distinct_Pair[(Current_IP_src, Current_IP_dst, Current_IP_proto)] = [1, [len(Packet[Current_IP_proto].payload)], 0]
        else:
            # Update the count and payload length list for the existing pair
            Distinct_Pair[(Current_IP_src, Current_IP_dst, Current_IP_proto)][0] += 1
            Distinct_Pair[(Current_IP_src, Current_IP_dst, Current_IP_proto)][1].append(len(Packet[Current_IP_proto].payload))
    except:
        pass

# Calculate the average payload length for each distinct pair
for Pair in Distinct_Pair:
    Distinct_Pair[Pair][2] = sum(Distinct_Pair[Pair][1]) / Distinct_Pair[Pair][0]

# Print a table header
print('The Table : ')
print('Source Ip | Destination Ip | Protocol | Number of Segments | Average Payload Length')

# Iterate through distinct pairs and print their information
for PAIR in Distinct_Pair:
    print(PAIR[0], ' | ', PAIR[1], ' | ', PAIR[2], ' | ', Distinct_Pair[PAIR][0], ' | ', Distinct_Pair[PAIR][2])
