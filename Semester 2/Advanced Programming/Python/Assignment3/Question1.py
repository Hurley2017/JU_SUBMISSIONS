#Assignment3 - Question1
import math
def isPrime(number):
    for i in range(2, math.floor(math.sqrt(number))+1):
        if(number%i == 0):
            return False
    return True
def prime_generator(limit):
    result = []
    for i in range(limit+1): #considering the limit
        if(isPrime(i)):
            result.append(i)
    return result

user_input = int(input("Enter the limit to find primes in between : "))
print(prime_generator(user_input))