d={}
fname=input("Enter Filename: ")
with open(fname,"r") as f:
    for line in f:
        wordlist=line.split()
        for word in wordlist:
            if word in d:
                d[word]+=1
            else:
                d[word]=1
print(d)
