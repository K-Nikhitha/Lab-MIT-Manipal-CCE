def multiplyFunc(a,b):
    c = a*b
    return c

def addFunc(a,b,c,d):
    x = multiplyFunc(a,b)
    y = multiplyFunc(c,d)
    return x+y

print("Enter 4 numbers:")
a = int(input())
b = int(input())
c = int(input())
d = int(input())
print(addFunc(a,b,c,d))
