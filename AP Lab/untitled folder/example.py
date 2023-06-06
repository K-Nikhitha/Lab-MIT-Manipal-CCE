import re
f2 = open('out.txt','a+')

def checkHash(p_i_d):
    regex=r'^#.*$'
    x=re.match(regex,p_i_d)
    if x:
        print("Has #"+p_i_d)
    else:
        print("No #"+p_i_d)
        
def checkValid(p_i_d):
    x=re.match(r'\d\d\w\w\w\d\d\d\d',p_i_d)
    if x:
        print("Valid")
    else:
        print("Invalid")
    
ch = 1
while ch!=6:
    print("1.Insert, 2.Display File, 3.Check #, 4.Valid ID, 5.Compute Total, 6.Exit")
    ch=int(input())
    if ch==1:
        f1 = open('inp.txt','a+')
        p_id=input("Enter Patient ID:")
        n=input("P Name:")
        pdb=int(input("Per Day Bill:"))
        d=int(input("No. of days:"))
        med=input("Medcines:")
        mb=int(input("Medicine Bill:"))
        l=[]
        l=[p_id,n,pdb,d,med,mb]
        data=','.join(str(i)for i in l)
        f1.write(data)
        f1.write('\n')
        f1.close()
        
    elif ch==2:
        f3 = open('inp.txt','r')
        x=f3.read()
        lines=x.split('\n')
        for line in lines:
            print(line)
        f3.close()
    elif ch==3:
        f3 = open('inp.txt','r')
        x=f3.read()
        lines=x.split('\n')
        for line in lines:
            atts=line.split(',')
            checkHash(atts[0])
        f3.close()
    elif ch==4:
        f3 = open('inp.txt','r')
        x=f3.read()
        lines=x.split('\n')
        for line in lines:
            atts=line.split(',')
            checkValid(atts[0])
        f3.close()
        
    else:
        exit()
