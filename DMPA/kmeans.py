data = [
    [1, 1],
    [2, 1],
    [4, 3],
    [5, 4]
]

x = [i[0] for i in data]
y = [i[1] for i in data]

import matplotlib.pyplot as plt

plt.scatter(x, y)
plt.show()

import math

def dist(center, point): #func to cal Euc dist
    d = 0.0
    for i in range(0,len(point)):
        d += (center[i]-point[i])**2
    return math.sqrt(d)


def calClusters(centers, dataset):
    clusters = []
    for i in range(len(dataset)):
        distances = []
        for c in centers:
            distances.append(dist(c, dataset[i]))
        temp = [z for z, val in enumerate(distances) if val == min(distances)]
        clusters.append(temp[0])
    return clusters


def calCenter(k, dataset, clusters): # calc mean of clusters
    nCenters = []
    for i in range(k):
        x = 0.0
        y = 0.0
        count = 0
        for j in range(len(clusters)):
            if (i == clusters[j]):
                x += dataset[j][0]
                y += dataset[j][1]
                count += 1
        x = x / count
        y = y / count
        nCenters.append([x, y])
    return nCenters


print("Enter number of clusters: ")
k = int(input())
centers = []
for i in range(k):
    print("Enter centre "+str(i)+" : ")
    t = [int(x) for x in input().split()]
    centers.append(t)

print("Initial centers: ")
print(centers)
print("Initial clusters: ")
clusters = calClusters(centers, data)
flag=True
itr=1
clus=[]
while flag==True:
    if clus == clusters:
        print("\n\nFinal Clusters:" )
        print(clusters)
        break
    else:
        clus=clusters
        centers = calCenter(k,data,clusters)
        clusters = calClusters(centers, data)
        print("Iteration "+str(itr))
        print("\nUpdated clusters: ")
        for i in range(k):
            print("cluster "+str(i))
            for j in range(len(clusters)):
                if(i == clusters[j]):
                    print(data[j],end=' ')
            print()
        print("\nUpdated centers: ")
        print(centers)
        print()
    itr+=1
