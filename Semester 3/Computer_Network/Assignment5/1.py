import copy
def NumToBin(num):
    bin = ''
    while num >= 2:
        bin += str(num%2)
        num = num//2
    bin += str(num)
    return int(bin[::-1])

def Network_Tuple(incoming):
    incoming = incoming.replace(" ", "")
    incoming = incoming.split("/")
    return (incoming[0], int(incoming[1]))

def Octates(Address):
    Oct = Address.split(".")
    for i in range(len(Oct)):
        Oct[i] = int(Oct[i])
    return Oct

def Wild_Card(Octates):
    Result = []
    for Octate in Octates:
        Result.append(Octate^255)
    return Result

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

def Subnet_Generator(Network_Bits):
    Host_Bits = 32-Network_Bits
    Host_Octates = Host_Bits//8
    build = []
    Net_Octates = Network_Bits//8
    Network_Bits = Network_Bits%8
    Limit = 7
    build += [255]*Net_Octates
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
    build += [0]*Host_Octates
    return build
        
def Network_ID(Network_Address, Network_Bits):
    Net_ID = []
    Net_Octates = Octates(Network_Address)
    Sub_Octates = Subnet_Generator(Network_Bits)
    for i in range(len(Net_Octates)):
        Net_ID.append(Net_Octates[i]&Sub_Octates[i])
    return Net_ID

def Total_Hosts(Network_Bits):
    Host_Bits = 32-Network_Bits
    Host = 0
    while Host_Bits != 0:
        Host += 2**(Host_Bits-1)
        Host_Bits -= 1
    return Host - 1

def Broadcast_ID(Network_Address, Network_Bits):
    Broad_ID = []
    Net_ID = Network_ID(Network_Address, Network_Bits)
    WildCard = Wild_Card(Subnet_Generator(Network_Bits))
    for i in range(len(Net_ID)):
        Broad_ID.append(Net_ID[i]|WildCard[i])
    return Broad_ID

def Host_IP_Generator(Network_Address, Network_Bits):
    Result = []
    Net_ID = Network_ID(Network_Address, Network_Bits)
    Total_Host = Total_Hosts(Network_Bits)
    j = 3
    for i in range(1, Total_Host+1):
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
        Result.append(copy.copy(Net_ID))
    return Result

def Data_Stringyfy(Result):
    for i in range(len(Result)):
        temp = ""
        for Oct in Result[i]:
            temp += "."+str(Oct)
        temp = temp[1:]
        Result[i] = temp
    return Result

# USER_INPUT = input("Enter Network Address : ")
# Network_Address, Network_Bits = Network_Tuple(USER_INPUT)
# print(Network_Address, Network_Bits)
# print("Network ID", Network_ID(Network_Address, Network_Bits))
# print("Subnet Mask", Subnet_Generator(Network_Bits))
# print("Wild Card", Wild_Card(Subnet_Generator(Network_Bits)))
# print("Total Hosts", Total_Hosts(Network_Bits))
# print("Broadcast ID", Broadcast_ID(Network_Address, Network_Bits))
# print("Generated Host IP", Data_Stringyfy(Host_IP_Generator(Network_Address, Network_Bits)))


