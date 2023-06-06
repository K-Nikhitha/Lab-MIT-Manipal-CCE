class Books:
    def __init__(self,author,title,price,publisher, copies):
        self.author=author
        self.title=title
        self.price=price
        self.publisher=publisher
        self.copies=copies

    def search_title(self,title):
        if(title==self.title):
            print(self.author,self.title,self.price,"\n")
        else:
            print("Not Present")
            

    def search_author(self,author):
        if(author==self.author):
             print("No of copies available= ",self.copies)
        else:
            print("Not Present")

    def buy_no_of_copies(self,num):
        if(num<=self.copies):
            print("Price of ",num,"copies is",num*self.price,"\n")
        else:
            print("Required Copies not in Stock","\n")


b1=Books("Prathmesh Sinha","Bank account of Life",100,"DOMIN8",10)
b2=Books("RRDOMIN8","Life of an Engineer",200,"Prathmesh",3)

ch = -1
while ch is not str(4):
    print("\nEnter 0 to search book using title")
    print("Enter 1 to search book using authon's name")
    print("Enter 2 to check for number of copies available")
    print("Enter 3 to exit")
    print("Enter your choice: ")
    
    ch = input()
    if ch == str(0):
        title= input("Enter title: ")
        b1.search_title(title)
        b2.search_title(title)
    if ch == str(1):
        auth = input("Enter author name: ")
        b1.search_author(auth)
        b2.search_author(auth)
    if ch == str(2):
        n=int(input("Enter the number of copies required"))
        b1.buy_no_of_copies(n)
        b2.buy_no_of_copies(n)
    if ch == str(3):
        print("BYE BYE")
        break





    

