import re
str1="abcdc"
str2="abcda"
regex = r'^[a-z]$|^([a-z]).*\1$'
x1=re.search(regex,str1)
x2=re.search(regex,str2)
if x1:
    print("Y")
else:
    print("N")
if x2:
    print("Y")
else:
    print("N")