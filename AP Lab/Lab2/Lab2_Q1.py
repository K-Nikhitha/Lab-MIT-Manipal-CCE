str = input('Enter String: ')
words = str.strip().split()
occ = {}
for word in words:

    if word in occ:
        occ[word] += 1
    else:
        occ[word] = 1

print(occ)
