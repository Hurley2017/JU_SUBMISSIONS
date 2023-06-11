# Write a python program to identify and extract numericals chunks
# from a text file and convert them into words;
# eg. 1992 -> “nineteen hundred and ninety two”

#a dictionary to store the numbers and their corresponding words
num_dict = {    0 : "Zero", 1 : "One", 2 : "Two", 3 : "Three", 4 : "Four", 5 : "Five",
                6 : "Six", 7 : "Seven", 8 : "Eight", 9 : "Nine", 10 : "Ten",
                11 : "Eleven", 12 : "Twelve", 13 : "Thirteen", 14 : "Fourteen",
                15 : "Fifteen", 16 : "Sixteen", 17 : "Seventeen", 18 : "Eighteen",
                19 : "Nineteen", 20 : "Twenty", 30 : "Thirty", 40 : "Forty",
                50 : "Fifty", 60 : "Sixty", 70 : "Seventy", 80 : "Eighty",
                90 : "Ninety", 100 : "Hundred(s)", 1000 : "Thousand(s)", 100000 : "Lakh(s)",
                10000000 : "Crore(s)"} #solo value upto 19 (atomic) and then rest are composite values

#recursive function to convert numbers to words
def n2w(number_input):
    if number_input < 20 and number_input > 0:
        return num_dict[number_input]
    elif number_input in num_dict:
        return num_dict[number_input]
    elif number_input < 100:
        return n2w(number_input - number_input % 10) + " " + n2w(number_input % 10)
    elif number_input < 1000 and number_input % 100 == 0:
        return num_dict[number_input // 100] + " " + n2w(100)
    elif number_input < 1000:
        return n2w(number_input // 100) + " " + n2w(100) + " " + n2w(number_input % 100)
    elif number_input < 10000 and number_input % 1000 == 0:
        return num_dict[number_input // 1000] + " " + n2w(1000)
    elif number_input < 100000:
        return n2w(number_input // 1000) + " " + n2w(1000) + " " + n2w(number_input % 1000)
    elif number_input < 1000000 and number_input % 100000 == 0:
        return num_dict[number_input // 100000] + " " + n2w(100000)
    elif number_input < 10000000:
        return n2w(number_input // 100000) + " " + n2w(100000) + " " + n2w(number_input % 100000)
    elif number_input < 100000000 and number_input % 10000000 == 0:
        return num_dict[number_input // 10000000] + " " + n2w(10000000)
    else:
        return n2w(number_input // 10000000) + " " + n2w(10000000) + " " + n2w(number_input % 10000000)

#filtering direct key hits from the dictionary
def direct_key_error(number_input):
    if number_input < 20 and number_input > 0:
        return num_dict[number_input]      
    elif number_input in num_dict:
        return "One " + num_dict[number_input]
    else:
        return n2w(number_input)

#taking input from the user
number_input = int(input("Enter the number : "))
number_string = direct_key_error(number_input)

#displaying the output
print("The number in words is : ", number_string)