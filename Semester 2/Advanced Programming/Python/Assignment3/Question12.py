ascii = []
for i in range(97, 123):
    ascii.append(i)

for i, item in enumerate(ascii, start=0):
    print(i,") ",item," : character = ",chr(item))