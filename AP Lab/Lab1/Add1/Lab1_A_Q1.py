n = int(input('Enter lower limit :'))
m = int(input('Enter upper limit'))

print('Prime numbers in the range are:')
for i in range(n,m+1):
    if i > 1:
        for j in range(2,i):
            if (i%j) == 0:
                break
        else:
            print(i)
