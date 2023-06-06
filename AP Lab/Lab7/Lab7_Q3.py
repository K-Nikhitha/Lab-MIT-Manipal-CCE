#fname=input("Enter Filename: ")
"""
f=open(fname,"r")
l = f.read()
lines = l.split('\n')
lnew=lines[::-1]
for line in lnew:
    print(line)
"""
with open('lab7.txt','r') as f:
    lines=f.read()
    print(lines)
    l=lines.split('\n')
    ln=l[::-1]
    print(ln)
