a = input('Enter List 1:')
list1 = a.split()
a = input('Enter list 2:')
list2 = a.split()
list_u = []
list_i = []
list_d_1 = []
list_d_2 = []

for i in list1:
    if i not in list_u:
        list_u.append(i)
    if i not in list_i and i in list2:
        list_i.append(i)
    if i not in list_d_1 and i not in list2:
        list_d_1.append(i)

for j in list2:
    if j not in list_u:
        list_u.append(j)
    if j not in list_d_2 and j not in list1:
        list_d_2.append(j)

print('Union: ',list_u)
print('Intersection: ', list_i)
print('Difference:')
print('A-B: ', list_d_1)
print('B-A: ', list_d_2)
