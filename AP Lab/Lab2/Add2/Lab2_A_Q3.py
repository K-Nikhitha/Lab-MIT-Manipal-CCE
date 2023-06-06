#Textfile
f= open("textFile.txt","a")
rep = 1
inp = []
print('Enter Strings:')
while rep==1:
    inp=input()
    f.write(inp)
    f.write("\n")
    rep = int(input('Rep ? :'))


f= open("textFile.txt","r")

lines = f.readlines()
d1={}
i=1
for line in lines:
   d[i]=len(line)-1
   i+=1

print(d1)

