#Dictionary Caching

cac_d = {}
rep = 1
while rep == 1:
    print('Enter 3 numbers to add:')
    a = int(input())
    b = int(input())
    c = int(input())
    if (a,b,c) in cac_d:
        print(cac_d[(a,b,c)],'Cach')
    else:
        cac_d[(a,b,c)] = a+b+c
        print(a+b+c)

    rep=int(input('Enter 1 to Continue; 0 to Exit:  '))
