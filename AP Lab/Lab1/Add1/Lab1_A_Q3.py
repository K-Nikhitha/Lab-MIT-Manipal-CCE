#Hexadecimal String

str = input('Enter String:')
f=0
for ch in str:
    if ((ch < 'A' or ch > 'F') and (ch <'0' or ch > '9')):
        f+=1
        break
if (f==0):
    print('Hexadecimal String')
else:
    print('Not a Hexadecimal String')


