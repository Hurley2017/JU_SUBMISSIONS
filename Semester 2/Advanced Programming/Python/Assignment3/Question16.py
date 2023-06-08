import collections
class Overload():
    def __init__(self):
        self.text = ''
        self.cObject = collections.Counter()
    def tokenize(self, text):
        tokens = text.split(" ")
        for token in tokens:
            if token not in self.cObject:
                self.cObject[token] = 1
            else:
                self.cObject[token] += 1
        
    def len(self):
        for Objects in self.cObject:
            print(self.cObject.keys() , " " , str(self.cObject[Objects]))
        print("Most Commonly Used")
        print(self.cObject.most_common(1))

Od = Overload()
Od.tokenize(input("Enter your Text: "))
Od.len()