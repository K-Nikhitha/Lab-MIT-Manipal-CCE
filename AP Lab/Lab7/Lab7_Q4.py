import re
fname = input("Enter Filename:")
f=open(fname,'r+')
f1=open('valid.txt','a+')
f2=open('invalid.txt','a+')
regex = r'([a-zA-Z0-9._])+@([A-Za-z])+\.([a-zA-z])'
l=f.read()
lines=l.split('\n')
for line in lines:
    print(line)
    if re.match(regex,line):
        f1.write(line)
        f1.write('\n')
    else:
        f2.write(line)
        f2.write('\n')