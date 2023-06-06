import revmod

str1 = input("Enter String:")
str2 = revmod.revstr(str1)
print("Reversed String:",str2)
if str1 == str2:
    print("Palindrome.")
else:
    print("Not a Palindrome.")
