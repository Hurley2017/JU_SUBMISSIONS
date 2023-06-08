def isValid(email):
    return True if "@" in email else False
def store(dict, name, age, email):
    if name in dict:
        raise Exception("name already in dictionary.")
    else:
        if age < 16:
            raise Exception("age is less than 16.")
        elif not isValid(email):
            raise Exception("Invalid email")
        else:
            dict[name] = True
            print("Successfully stored.")


dictionary = {}
while(True):
    print(dictionary)
    print("Press CTRL+C to Quit")
    user_input_name = input("Enter name : ")
    user_input_age = int(input("Enter age : "))
    user_input_email = input("Enter email : ")
    store(dictionary, user_input_name, user_input_age, user_input_email)