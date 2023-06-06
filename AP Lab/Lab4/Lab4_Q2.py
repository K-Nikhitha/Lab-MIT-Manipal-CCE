import cmath

x = int(input("Enter Real part of the complex number:"))
y = int(input("Enter Imaginary part of the complex number:"))
n = complex(x,y)
print("Sine:", cmath.sin(n))
print("Square Root:", cmath.sqrt(n))
print("Log:", cmath.log10(n))
