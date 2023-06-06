n = int(input("Enter the number of employees:"))
print("Enter Id, Name, Salary, Department (Separated by Comma):")
lis = []
for i in range(n):
    x= input()
    tup = tuple(x.split(","))
    lis.append(tup)
f=0
eid =input("\nEnter Id to search:")
for i in lis:
    if i[0] == eid:
        print(i)
        f+=1
if f==0:
    print("ID Not Found")

    
    
