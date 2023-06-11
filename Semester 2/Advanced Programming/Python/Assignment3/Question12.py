# Enumerate the sequence of all lowercase ASCII letters, starting from 1, using enumerate.

ascii = []

#appending the ascii values of the lowercase letters to the list
for i in range(97, 123):
    ascii.append(i)

#using enumerate to print the ascii values of the lowercase letters
for i, item in enumerate(ascii, start=0):
    print(i,") ",item," : character = ",chr(item))