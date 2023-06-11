# Write a simple program which loops over a list of user data ( tuples containing a username, email, and age )
# and adds each user to a directory if the user is at least 16 years old. 
# You do not need to store age. 
# Write a simple exception hierarchy which defines different exception for each of these error conditions:
# i) the username is not unique
# ii) the age is not positive integer
# iii) the user is under 16
# iv) the email address is not valid ( a simple check for a username, the @ symbol and a domain name is sufficient )
# Raise these exceptions in your program where appropriate.
# Whenever an exception occurs your program should move onto the next set of data in the list.
# Print a different error message for each different kind of exception.

List_of_Tuples = [('Tusher', 23, 'tusher@gmail.com'), #valid data
              ('Dwip', 23, 'deep@gmail.com'), #valid data
              ('Sudip', 23, 'sudip@gmail.com'), #valid data
              ('dummy', 14, 'dummy@gmail.com'), #invalid data
              ('Sudip', 23, 'sudip@gmail.com'), #invalid data
              ('dummy2', -12, 'dummy@gmail.com'), #invalid data 
              ('dummy3', 22, 'dummygmail.com')] #invalid data

directory = {} #dictionary to store the valid data

for Tuples in List_of_Tuples:
    try:
        print("For Tuple : ", Tuples, " :")
        #checking for the exceptions
        if Tuples[1] < 0:
            raise Exception('The user age is not positive integer')
        elif Tuples[1] < 16:
            raise Exception('The user is under 16')
        elif Tuples[0] in directory:
            raise Exception('The username is not unique')
        elif '@' not in Tuples[2]:
            raise Exception('The email address is not valid')
        else:
            directory[Tuples[0]] = "" #adding the valid data to the dictionary
            print("Valid data")
    except Exception as e:
        print(e) #printing the error message
        continue

print(directory) #printing resultant directory