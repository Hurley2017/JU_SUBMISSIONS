# Write a regular expression to validate a phone number.

import re  # importing regular expression module

# function to check if the phone number is valid or not
def isValid(user_input):
    pattern = r'^(?:\+91)?[6-9]\d{9}$' #pattern for validating the phone number
    if re.match(pattern, user_input):
        return True
    else:
        return False

#Taking input from the user
user_input = input("Enter phone number : ")

#displaying the result
print("This is phone number is : ", isValid(user_input))