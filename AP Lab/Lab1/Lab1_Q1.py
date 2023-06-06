l1= []
l2 = []
n1 = int(input('Enter number of elements in L1:'))
print('Enter elements of L1:')
for i in range(n1):
    l1.append(int(input()))
n2 = int(input('Enter number of elements in L2:'))
print('Enter elements of L2:')
for i in range(n2):
    l2.append(int(input()))

l3 = []
for i in l1:
    if i%2 !=0:
        l3.append(i)

for i in l2:
    if i%2==0:
        l3.append(i)

print(l3)
