# Filter out the odd squares using map, filter, list

#function to find the squares
def odd_squares(n):
    return n**2

#function to find the odd numbers
def odd(n):
    return n%2 != 0

def main():
    #taking input from the user
    n = int(input("Enter the number of elements in the list: "))
    l = []

    for i in range(n):
        l.append(int(input(f"Element {i} : ")))
    
    print("The list is: ", l) #printing the list
    print("The odd squares of the list are: ", list(map(odd_squares,list(filter(odd,l))))) #printing the odd squares of the list and filtering out the odd numbers

main() #calling the main function
