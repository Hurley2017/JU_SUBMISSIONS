coupon_dictionary = {
    "Sunday" : "80%",
    "Monday" : "10%",
    "Tuesday" : "30%",
    "Wednesday" : "20%",
    "Thursday" : "40%",
    "Friday" : "60%",
    "Saturday" : "50%"
}
mapped_day = {
    1 : "Sunday",
    2 : "Monday",
    3 : "Tuesday",
    4 : "Wednesday",
    5 : "Thursday",
    6 : "Friday",
    7 : "Saturday"
}
def return_day(mapped_day, number):
    return mapped_day[number]
def return_discount(coupon_dictionary, day):
    return coupon_dictionary[day]

print("Choose the day : \n")
print("[1-7] i.e, 1 for 'Monday' & '7' for 'Sunday'\n")
user_choice = int(input("Enter your choice : "))
print(f"Your discount is {return_discount(coupon_dictionary, return_day(mapped_day, user_choice))}.\n")