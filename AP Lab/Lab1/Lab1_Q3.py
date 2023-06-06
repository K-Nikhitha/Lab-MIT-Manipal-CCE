n = int(input('Enter number of strings:'))
str = []
print('Enter the strings:')
for i in range(n):
    str.append(input())
c=0
for i in str:
    if i[0]==i[-1] and len(i)>2:
        c+=1

print('Number of strings with same first and last characters and having length of more than 2: ',c)

print('Strings with odd length:')
for i in str:
    if len(i) % 2 !=0:
        print(i)
