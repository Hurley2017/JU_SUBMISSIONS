#Write a discount coupon code using a dictionary in python with different rate coupons for each day of week.

# dictionary containing the coupon codes respective to the days
coupon_dictionary = {
    "Sunday" : "80%",
    "Monday" : "10%",
    "Tuesday" : "30%",
    "Wednesday" : "20%",
    "Thursday" : "40%",
    "Friday" : "60%",
    "Saturday" : "50%"
}

# mapping the days to numbers
mapped_day = {
    1 : "Sunday",
    2 : "Monday",
    3 : "Tuesday",
    4 : "Wednesday",
    5 : "Thursday",
    6 : "Friday",
    7 : "Saturday"
}

# function to return the day
def return_day(mapped_day, number):
    return mapped_day[number]

# function to return the discount
def return_discount(coupon_dictionary, day):
    return coupon_dictionary[day]

# Getting user input
print("Choose the day : \n")
print("[1-7] i.e, 1 for 'Sunday' & '7' for 'Saturday'\n")
user_choice = int(input("Enter your choice : "))

#displaying the result
print(f"Your discount is {return_discount(coupon_dictionary, return_day(mapped_day, user_choice))}.\n")