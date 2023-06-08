import os
def findfiles(dir):
    path = []
    rec(dir, path)
    return path


def rec(dir, path):
    for fname in os.listdir(dir):
        fp = os.path.join(dir, fname)
        if os.path.isdir(fp):
            rec(fp, path)
        else:
            path.append(fp)


dir = input("Enter dir : ")
file = findfiles(dir)
for f in file:
    print(f)

