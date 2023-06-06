#Armstrong Number

n = int(input('Enter a number:'))
num = n
s=0
while n>0:
    r=n%10
    s=s+(r*r*r)
    n=n//10

if s==num:
    print('Armstrong Number')
else:
    print('Not an Armstrong Number')
