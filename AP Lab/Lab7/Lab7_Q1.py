fname = input("Enter filename:")
words=0
lines=0
chars=0
with open(fname,'r') as f:
    for line in f:
        lines+=1
        wordlist = line.split()
        words += len(wordlist)
        chars += len(line)
print("Lines: ",lines)
print("Words: ",words)
print("Characters ",chars)
