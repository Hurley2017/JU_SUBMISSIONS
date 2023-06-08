#filter out the odd squares using map, filter and list

def odd_squares(n):
    return n**2

def odd(n):
    return n%2 != 0

def main():
    n = int(input("Enter the number of elements in the list: "))
    l = []
    for i in range(n):
        l.append(int(input("Enter the element: ")))
    print("The list is: ", l)
    print("The odd squares of the list are: ", list(map(odd_squares,list(filter(odd,l)))))

main()