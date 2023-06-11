# Write an operator overloading for len which shows string length 
# for any given string and return only length of repetitive words with the text 
# if the text has some repetitive parts. 
# Determine the most frequently occurring words using most_common.

import collections #importing the collections module

#class to find the length of the string and the most commonly used words
class Overload():
    #constructor
    def __init__(self):
        self.text = ''
        self.cObject = collections.Counter() #creating a Collection Counter object
    
    #function to find the occurrence of a particular token in a given string
    def tokenize(self, text):
        tokens = text.split(" ")
        for token in tokens:
            if token not in self.cObject:
                self.cObject[token] = 1
            else:
                self.cObject[token] += 1

    #function to find the length of the string and the most commonly used words  
    def len(self):
        for Objects in self.cObject:
            print(Objects , " " , str(self.cObject[Objects]))
        print("Most Commonly Used") #printing the most commonly used words
        print(self.cObject.most_common(1)) #printing the most commonly used word

#creating an object of the class
Od = Overload()
Od.tokenize(input("Enter your Text: ")) #taking input from the user
Od.len() #calling the overloaded len function