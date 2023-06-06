import csv
data=[]
with open('apr1.csv') as f:
    rec = csv.reader(f)
    data=list(rec)
print("Input Data from CSV:\n\n")
print(data)

print("\nInitial Set of Items:\n")
init=[]
for i in data:
    for j in i:
        if j not in init:
            init.append(j)
init=sorted(init)
print(init)
minsup = int(input("Enter Minimum Support:"))
#sup = minsup*len(init)
print(minsup)

from collections import Counter

c = Counter()
for i in init:
    for d in data:
        if i in d:
            c[i]+=1

print("C1:")
for i in c:
   print(str([i])+": "+str(c[i]))
#print(c)
print()
l = Counter()
for i in c:
    if(c[i] >= minsup):
        l[frozenset([i])]+=c[i]
print("L1:")
#print(l)
for i in l:
    print(str(list(i))+": "+str(l[i]))
print()

l1 = l
pos = 1

for count in range (2,20):
    st = set()
    temp = list(l)
    for i in range(0,len(temp)):
        for j in range(i+1,len(temp)):
            t = temp[i].union(temp[j])
            if(len(t) == count):
                st.add(temp[i].union(temp[j]))
            #print(st) #Union of frozensets to create combinations

    st = list(st)
    c = Counter()
    for i in st:
        c[i]=0
        for d in data: #for every row in data
            temp=set(d)
            if(i.issubset(temp)): #check if the combos are present in the data row
                c[i]+=1
    print("C"+str(count)+" : ")
    for i in c:
        print(str(list(i))+" : "+ str(c[i]))
    print()

    l = Counter()
    for i in c:
        if(c[i]>= minsup):   #pruning
            l[i]+=c[i]
    
    print("L"+str(count)+" : ")
    for i in l:
        print(str(list(i))+" : "+str(l[i]))
    print()
    if(len(l)==0):
        break
    pl = l
    pos = count
print("Result: ") #print final L
print("L"+str(pos)+" : ")
for i in pl:
    print(str(list(i))+" : ")
print()


#Association Rules
