# Write a prime generator program using only primes and using python loops.

import math

# function to check if a number is prime or not
def isPrime(number):
    for i in range(2, math.floor(math.sqrt(number))+1):
        if(number%i == 0):
            return False
    return True

# function to generate prime numbers
def prime_generator(limit):
    result = []
    for i in range(2, limit+1): #considering the limit
        if(isPrime(i)):
            result.append(i)
    return result

#printing the result
user_input = int(input("Enter the limit to find primes in between : "))
print(prime_generator(user_input))