print('Matrix 1')
r1= int(input("Enter the number of rows: "))
c1= int(input("Enter the number of columns: "))
print('Enter Values of Matrix 1:')
matrix1 = {}
for i in range(r1):
    for j in range(c1):
        inp = int(input())
        if inp != 0:
            matrix1[(i,j)]=inp
            
print('\nMatrix 2')
r2= int(input("Enter the number of rows: "))
c2= int(input("Enter the number of columns: "))
print('Enter Values of Matrix 2:')
matrix2 = {}
for i in range(r2):
    for j in range(c2):
        inp = int(input())
        if inp != 0:
            matrix2[(i,j)]=inp

matrix3 = {}
for i in range(r1):
    for j in range(c1):
        if (i,j) in matrix1 and (i,j) in matrix2:
            matrix3[(i,j)] = matrix1[(i,j)]+matrix2[(i,j)]
        elif (i,j) not in matrix1 and (i,j) in matrix2:
            matrix3[(i,j)]=matrix2[(i,j)]
        elif (i,j) not in matrix2 and (i,j) in matrix1:
            matrix3[(i,j)]=matrix1[(i,j)]
        else:
            matrix3[(i,j)] = 0
        

print("\nFinal Matrix:\n")
for i in range(r1):
    for j in range(c1):
        print(matrix3[(i,j)],end=" ")
    print()
