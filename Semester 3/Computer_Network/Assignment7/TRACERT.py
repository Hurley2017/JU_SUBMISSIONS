from scapy.all import sr1, ICMP, IP

# Function to perform traceroute
def traceroute(URL, MAX_HOPS):
    SUCCESS = False  # Flag to track successful reach to destination
    # Iterate through TTL values from 1 to MAX_HOPS
    for TTL in range(1, MAX_HOPS+1):
        # Create an ICMP packet with increasing TTL to trace the route
        Packet = IP(dst=URL, ttl=TTL) / ICMP() / 'Hello World'
        # Send the packet and wait for a reply (1 second timeout)
        Reply = sr1(Packet, verbose=False, timeout=1)
        
        # Check the reply
        if Reply is None:
            # No reply received within the timeout, print '* * *'
            print('TTL: ', TTL, ' * * *')
        elif Reply.type == 0:  # ICMP Echo Reply received (destination reached)
            # Print the TTL and the source IP
            print('TTL: ', TTL, ' ', Reply.src)
            print('Reached Destination')
            SUCCESS = True  # Set success flag to True
            break  # Exit the loop, destination reached
        else:
            # Intermediate hop reached, print the TTL and source IP
            print('TTL: ', TTL, ' ', Reply.src)
    
    # If destination not reached, print 'Destination Unreachable'
    if not SUCCESS:
        print('Destination Unreachable')

# Input URL and maximum hops
URL = input('Enter URL: ')
MAX_HOPS = int(input('Enter Max Hops: '))
traceroute(URL, MAX_HOPS)  # Call the traceroute function
