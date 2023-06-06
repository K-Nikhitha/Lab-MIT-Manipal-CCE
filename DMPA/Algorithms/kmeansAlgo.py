import csv
import math
data = []

with open('km1.csv') as f:
    rec = csv.reader(f)
    for row in rec:
        row[0]=int(row[0])
        row[1]=int(row[1])
        #print(row)
        data.append(row)
print("Input Data from CSV:\n\n")
print(data)

def eucDist(center,point):
    d=0.0
    for i in range(0,len(point)):
        d += (center[i]-point[i])**2
    return math.sqrt(d)

def manDist(center,point):
    d=0.0
    for i in range(0,len(point)):
        d+=abs(center[i]-point[i])
    return d

def assignClusters(centers,data):
    clusters = []
    for i in range(len(data)):
        dist=[]
        for c in centers:
            #dist.append(eucDist(c,data[i]))
            dist.append(manDist(c,data[i]))
            print(dist)
        if dist[0]<dist[1]:
            clusters.append('C1')
        else:
            clusters.append('C2')
        #temp = [z for z, val in enumerate(dist) if val == min(dist)]
        #clusters.append(temp[0])
    return clusters
    #print(clusters)

def calCenters(k,data,clusters):
    nCenters = []
    for i in range(1,k+1):
        x = 0.0
        y = 0.0
        count = 0
        for j in range(len(clusters)):
            if(("C"+str(i))==clusters[j]):
                x += data[j][0]
                y += data[j][1]
                count+=1
        x = x/count
        y = y/count
        nCenters.append([x,y])
    return nCenters


k = int(input("Enter the number of clusters:"))
centers = []
for i in range(k):
    print("Enter Center "+str(i)+" : ")
    t = [int(x) for x in input().split(",")]
    centers.append(t)

print("Initial Centers: ")
print(centers)
clusters = assignClusters(centers,data)
print("Initial Clusters : ")
for i in range(1,k+1):
    print("Cluster "+str(i))
    for j in range(len(clusters)):
        if(("C"+str(i))==clusters[j]):
            print(data[j],end=" ")
    print()
print()

flag = True
itr = 1
clus=[]
while flag == True:
    if clus == clusters:
        print("\n\nFinal Clusters:" )
        print(clusters)
        break
    else:
        clus = clusters
        centers = calCenters(k,data,clusters)
        clusters = assignClusters(centers,data)
        print("Iteration "+str(itr))
        print("\nUpdated Clusters: ")
        for i in range(1,k+1):
            print("Cluster: "+str(i))
            for j in range(len(clusters)):
                if(("C"+str(i))==clusters[j]):
                    print(data[j],end=" ")
            print()
        print("Updated Centers: ")
        print(centers)
        print()
    itr+=1