import copy
from scapy.all import IP, TCP, ICMP, srloop, sr1

# Function for sending a TCP SYN packet and checking if the host is alive
def TCP_SEND(Host, Port, Alive_Hosts):
    # Create a TCP SYN packet
    Packet = IP(dst=Host) / TCP(dport=Port, flags="S")
    
    # Send the packet and wait for a response (SYN-ACK)
    Response = sr1(Packet, timeout=1)
    
    # If a response is received and it has the SYN-ACK flags set, mark the host as alive
    if Response != None and Response['TCP'].flags == "SA":
        print(Response['TCP'].flags)
        Alive_Hosts.add((Host, Port))

# Function for sending an ICMP echo request (ping) and checking if the host responds
def Echo_Ping(Host_Address):
    # Create an ICMP echo request packet
    Packet = IP(dst=Host_Address) / ICMP() / "Hello"
    
    # Send the packet and check for a response within the timeout
    Result = srloop(Packet, count=1, timeout=1)[0]
    
    # If a response is received and it has ICMP type 0 (echo reply), consider the host alive
    if len(Result) == 0:
        return False
    elif Result[0][1]['ICMP'].type == 0:
        return True
    else:
        return False

# Function to convert a decimal number to binary as an integer
def NumToBin(num):
    bin = ''
    while num >= 2:
        bin += str(num % 2)
        num = num // 2
    bin += str(num)
    return int(bin[::-1])

# Function to parse a network tuple in the format "IP/NetMask"
def Network_Tuple(incoming):
    incoming = incoming.replace(" ", "")
    incoming = incoming.split("/")
    return (incoming[0], int(incoming[1]))

# Function to split an IP address string into octets and convert them to integers
def Octates(Address):
    Oct = Address.split(".")
    for i in range(len(Oct)):
        Oct[i] = int(Oct[i])
    return Oct

# Function to calculate the wildcard mask for a given set of octets
def Wild_Card(Octates):
    Result = []
    for Octate in Octates:
        Result.append(Octate ^ 255)
    return Result

# Function to determine the IP address class based on the first octet
def Return_Class(Network_Address):
    Octates = Octates(Network_Address)
    FOctate = int(Octates[0])
    if FOctate < 128:
        return "A"
    elif FOctate < 192:
        return "B"
    elif FOctate < 224:
        return "C"
    elif FOctate < 240:
        return "D"
    elif FOctate < 256:
        return "E"
    else:
        return None

# Function to generate a subnet mask as a list of octets
def Subnet_Generator(Network_Bits):
    Host_Bits = 32 - Network_Bits
    Host_Octates = Host_Bits // 8
    build = []
    Net_Octates = Network_Bits // 8
    Network_Bits = Network_Bits % 8
    Limit = 7
    build += [255] * Net_Octates
    if Network_Bits != 0:
        S = 0
        while True:
            if Network_Bits != 0:
                S += 2**(Limit)
                Network_Bits -= 1
                Limit -= 1
            else:
                break
        build.append(S)
    build += [0] * Host_Octates
    return build

# Function to calculate the network ID by applying a subnet mask
def Network_ID(Network_Address, Network_Bits):
    Net_ID = []
    Net_Octates = Octates(Network_Address)
    Sub_Octates = Subnet_Generator(Network_Bits)
    for i in range(len(Net_Octates)):
        Net_ID.append(Net_Octates[i] & Sub_Octates[i])
    return Net_ID

# Function to calculate the total number of host IP addresses in a subnet
def Total_Hosts(Network_Bits):
    Host_Bits = 32 - Network_Bits
    Host = 0
    while Host_Bits != 0:
        Host += 2**(Host_Bits - 1)
        Host_Bits -= 1
    return Host - 1

# Function to calculate the broadcast address by applying a wildcard mask to the network ID
def Broadcast_ID(Network_Address, Network_Bits):
    Broad_ID = []
    Net_ID = Network_ID(Network_Address, Network_Bits)
    WildCard = Wild_Card(Subnet_Generator(Network_Bits))
    for i in range(len(Net_ID)):
        Broad_ID.append(Net_ID[i] | WildCard[i])
    return Broad_ID

# Function to generate a list of host IP addresses within a subnet
def Host_IP_Generator(Network_Address, Network_Bits):
    Result = []
    Net_ID = Network_ID(Network_Address, Network_Bits)
    Total_Host = Total_Hosts(Network_Bits)
    j = 3
    for i in range(1, Total_Host + 1):
        if Net_ID[j] < 255:
            Net_ID[j] += 1
        else:
            Net_ID[j] = 0
            j -= 1
            if Net_ID[j] < 255:
                Net_ID[j] += 1
            else:
                Net_ID[j] = 0
                j -= 1
                if Net_ID[j] < 255:
                    Net_ID[j] += 1
                else:
                    Net_ID[j] = 0
                    j -= 1
                    Net_ID[j] += 1
                    j += 1
                j += 1
            j += 1
        Result.append(Strfy(copy.copy(Net_ID)))
    return Result

# Function to convert a list of octets representing an IP address back to a string format
def Strfy(IPV4):
    temp = ""
    for Oct in IPV4:
        temp += "." + str(Oct)
    return temp[1:]

# Function to convert a list of IP addresses represented as lists of octets to string format
def Data_Stringyfy(Result):
    for i in range(len(Result)):
        Result[i] = Strfy(Result[i])
    return Result
