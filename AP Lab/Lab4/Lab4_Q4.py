import datetime

name = input("Enter Name:")
current_time = datetime.datetime.now()
if current_time.hour > 12:
    print("Good Evening", name)
elif current_time.hour == 12:
    print("Good Noon", name)
else:
    print("Good Morning", name)
