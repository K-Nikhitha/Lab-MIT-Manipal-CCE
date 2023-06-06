def multiply_list(lis):
    m=1
    for i in lis:
        m*=int(i)
    return m

inp = input('Enter Elements of list (separated by space):')
lis = inp.split()
x = multiply_list(lis)
print('Multiplied Value:',x)
