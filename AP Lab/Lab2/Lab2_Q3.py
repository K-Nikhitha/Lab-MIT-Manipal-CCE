import random

n = int(input('Enter number of dictionary entries:'))
print('Enter the dictionary entries:')
d = {}
ran = []
for i in range(n):
    r = random.randint(0,100)
    if r not in ran:
        ran.append(r)
        d[r]=input()
    else:
        i-=1

s=0
c=0
str=''
for i in d:
    if d[i].isnumeric():
        s+=int(d[i])
        c+=1
    else:
        str+=d[i]

print('Average of all numbers in the dictionary:',s/c)
print('Concatenated Strings:', str)

e = input('Enter string to search:')
if e in d.values():
    print('String is found.')
else:
    print('String not found.')


print('Strings with only special character in the dictionary:')
allowed='!@#$%^&*?'
for i in d:
    if all(ch in allowed for ch in d[i]):
        print(d[i])
