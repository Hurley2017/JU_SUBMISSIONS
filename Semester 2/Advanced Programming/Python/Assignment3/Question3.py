from itertools import compress
#using iterator
save1 = save2 = 0
print("Using Iterator : \n")
top10 = [1]*20
even = iter(top10)
odd = iter(top10)
save1 += next(even)
save1 += next(even)
save2 += next(odd)
print("Printing odd  : ")
while save2 != None:
    print(save2)
    try:
        save2 += next(odd)
        save2 += next(odd)
    except:
        print("Odd printing stopped!\n")
        break
print("Printing even  : ")
while save1 != None:
    print(save1)
    try:
        save1 += next(even)
        save1 += next(even)
    except:
        print("Even printing stopped!\n")
        break
#using compress
print("Using Compress : \n")
top10 = []
even_bool = []
odd_bool = []
for i in range(1, 21):
    if(i%2 == 0):
        even_bool.append(True)
        odd_bool.append(False)
    else:
        even_bool.append(False)
        odd_bool.append(True)
    top10.append(i)
odd_data = compress(top10, odd_bool)
even_data = compress(top10, even_bool)
print("Printing even data : ")
for data in odd_data:
    print(data)
print("printing odd data : ")
for data in even_data:
    print(data)
print("Ended!\n")