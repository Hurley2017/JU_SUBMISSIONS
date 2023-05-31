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
top10 = [1]*20