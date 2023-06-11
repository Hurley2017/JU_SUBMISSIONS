# Write a function findfiles 
# that recursively descends the directory tree 
# for the specified directory 
# and generates paths of all the files in the tree.

import os

#function to find all the files in the directory
def findfiles(dir, path):
    for fname in os.listdir(dir):
        fp = os.path.join(dir, fname) #joining the path to the directory name
        if os.path.isdir(fp): #checking if the path is a directory
            findfiles(fp, path)
        else: #if the path is a file then append it to the list
            path.append(fp)
    return path

#Taking input from the user
dir = input("Enter dir : ")
all_files = findfiles(dir, [])

#printing the result
for files in all_files:
    print(files)

