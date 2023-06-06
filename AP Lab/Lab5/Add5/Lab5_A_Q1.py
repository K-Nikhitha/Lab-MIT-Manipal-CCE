class Employee:
    empid = 2912
    totsal = 0
    def __init__(self, name, sal, dept):
        self.eid = Employee.empid
        self.name = name
        self.sal=sal
        self.dept=dept
        Employee.empid+=1
        
    def __del__(self):
        print("Destructor")

    def disp(self,x):
        if self.eid == x:
            print("Employee ID:", self.eid)
            print("Emplooyee Name:", self.name)
            print("Employee Salary:", self.sal)
            print("Employee Department:", self.dept)

    def salTot(self):
        totsal += self.sal

lis=[]
n = int(input("Enter the number of employees:"))
print("Enter Name, Salary and Department of each employee:")
for i in range(n):
    na = input()
    s = int(input())
    d = input()
    lis.append(Employee(na,s,d))

x = int(input("Enter Employee Id to search:"))
for obj in lis:
    obj.disp(x)
