def rem_dup(lis):
    lis2=[]
    for i in lis:
        if i not in lis2:
            lis2.append(i)
    return lis2


inp = input('Enter List to remove duplicates (separated by space):')
lis = inp.split()
lis2 = rem_dup(lis)
print(lis2)
