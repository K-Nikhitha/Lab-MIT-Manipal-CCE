class Subset:  
    def subs(self, uset):  
        return self.recsub([], sorted(uset))  
 
    def recsub(self, curr, uset):  
        if uset:  
            return self.recsub(curr, uset[1:]) + self.recsub(curr + [uset[0]], uset[1:])  
        return [curr]  
a=[]
n=int(input("Enter number of elements of list: "))
print("Enter elements:")
for i in range(n):
    a.append(int(input()))
print("Subsets: ")
print(Subset().subs(a))
