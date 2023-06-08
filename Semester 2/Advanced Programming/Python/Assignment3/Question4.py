import re 
def isValid(user_input):
    pattern = r'^(?:\+91)?[6-9]\d{9}$'
    if re.match(pattern, user_input):
        return True
    else:
        return False


user_input = input("Enter phone number : ")
print("This is phone number is : ", isValid(user_input))