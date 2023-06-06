import csv

data = []

with open('naivedata.csv') as f:
    rec = csv.reader(f)
    data = list(rec)
    for i in range(len(data)):
       data[i] = [float(x) for x in data[i]]

#print(data)

def separate_by_class(data):
    classes = dict()
    for row in data:
        if(row[-1] not in classes):
            classes[row[-1]] = []
        classes[row[-1]].append(row)
    return classes

classes = separate_by_class(data)
for label in classes:
    print(label)
    print()
    for row in classes[label]:
        print(row)
    print()

tc=len(data) #total
c1=0 #count(yes)
c0=0 #count(no)
for row in data:
    if row[-1]==0:
        c0+=1
    else:
        c1+=1
prob1 = c1 / tc #P(class=yes)
prob0 = c0 / tc #P(class=no)

#test = [0,1,1,0] #test case X
#Ans = Yes = 1

test = [1,93,70,31,0,30.4,0.315,23]
probYes=1
for i in range(len(test)):
        count = 0
        for row in classes[1.0]:
            if(test[i]==row[i]):
                count+=1
        print('Feature '+str(i+1))
        print(str(count)+'/'+str(c1))
        probYes *= count/c1

print("P(X/class = yes) : "+str(probYes)) #P(X/class = yes)

probNo=1 #
for i in range(len(test)):
        count = 0
        for row in classes[0.0]:
            if(test[i]==row[i]):
                count+=1
        print('Feature '+str(i+1))
        print(str(count)+'/'+str(c0))
        probNo *= count/c0

print("P(X/class = no) : "+str(probNo)) #P(X/class = no)

probYes *= prob1
probNo *= prob0
#to find final class
'''
print("Probablity of Yes:"+str(probYes))
print("Probability of No:"+str(probNo))
'''
if probYes>=probNo:
    print("Yes")
else:
    print("No")