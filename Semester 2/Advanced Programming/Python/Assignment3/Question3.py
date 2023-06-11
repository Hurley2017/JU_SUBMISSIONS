# Print first 10 odd and even numbers using iterators and compress. You can use duck typing.

from itertools import compress #importing compress

#using iterator
save1 = save2 = 0

print("Using Iterator : \n")
top10 = [1]*20 #creating a list of 20 1's
even = iter(top10) #creating an iterator for even numbers
odd = iter(top10) #creating an iterator for odd numbers

#skipping twice to get the first even number [not considering 0 as even]
save1 += next(even)
save1 += next(even)
#skipping once to get the first odd number
save2 += next(odd)

print("Printing odd  : ")
while save2 != None:
    print(save2) #printing the odd number and increasing the save2 by 2 after each iteration
    try:
        save2 += next(odd)
        save2 += next(odd)
    except:
        print("Odd printing stopped!\n")
        break

print("Printing even  : ")
while save1 != None:
    print(save1) #printing the even number and increasing the save1 by 2 after each iteration
    try:
        save1 += next(even)
        save1 += next(even)
    except:
        print("Even printing stopped!\n")
        break

#using compress
print("Using Compress : \n")
top10 = [] #for storing the numbers
even_bool = [] #for storing the boolean values for even numbers
odd_bool = [] #for storing the boolean values for odd numbers

#since we need only 10 numbers, we are considering the limit as 20
for i in range(1, 21):
    if(i%2 == 0):
        even_bool.append(True)
        odd_bool.append(False)
    else:
        even_bool.append(False)
        odd_bool.append(True)
    top10.append(i)

odd_data = compress(top10, odd_bool) #using compress to get the odd numbers
even_data = compress(top10, even_bool) #using compress to get the even numbers

#displaying the result for even numbers
print("Printing even data : ")
for data in odd_data:
    print(data)

#displaying the result for odd numbers
print("printing odd data : ")
for data in even_data:
    print(data)

print("Ended!\n")