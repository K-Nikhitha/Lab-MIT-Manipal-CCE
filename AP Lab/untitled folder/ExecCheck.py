import sqlite3
import re
#from sqlite3.dbapi2 import Cursor
conn = sqlite3.connect("eval.db")
cursor=conn.cursor()
print("Database connected successfully")

creattablequery = "CREATE TABLE CAR ( ENGNUM TEXT NOT NULL, REGNO TEXT PRIMARY KEY NOT NULL, COLOR TEXT NOT NULL, OWNER TEXT NOT NULL, MODEL TEXT NOT NULL)"
cursor.execute(creattablequery)
print("Table Created successfully")

ch = -1

#def insert(ENGNUM,REGNO,COLOR,OWNER,MODEL):
def insert(E,R,C,O,M):
    #insertquery = """INSERT INTO CAR (ENGNUM,REGNO,COLOR,OWNER,MODEL) VALUES (E,R,C,O,M)"""
    #insertquery = "INSERT INTO CAR(ENGNUM,REGNO,COLOR,OWNER,MODEL) VALUES ("+"'"+ENGNUM+"'"+","+"'"+REGNO+"'"+","+"'"+COLOR+"'"+","+"'"+OWNER+"'"+","+"'"+MODEL+"'"+")"
    #conn.execute(insertquery)
    cursor.execute("""INSERT INTO CAR (ENGNUM,REGNO,COLOR,OWNER,MODEL) VALUES (?,?,?,?,?)""",(E,R,C,O,M))
    conn.commit()
    print("VALUES INSERTED\n")

def display():
    displayquery = "SELECT ENGNUM,REGNO,COLOR,OWNER,MODEL FROM CAR WHERE OWNER LIKE 'S%'"
    result = conn.execute(displayquery)
    if result.rowcount == 0:
        print("No Values present: ")
    for row in result:
        print("\nENGNUM: ",row[0])
        print("REGNO: ",row[1])
        print("COLOR: ",row[2])
        print("OWNER: ",row[3])
        print("MODEL: ",row[4])
    print("Operation Done successfully\n")

    
    
while ch is not str(4):
    print("Enter 1 to display OWNER from student table")
    print("Enter 2 to insert values in CAR table")
    print("Enter 3 to exit")
    print("Enter your choice: ")

    ch = input()
    if ch==str(1):
        display()
    if ch == str(2):
        e = input("Enter ENGNUM:")
        ENGNUM = re.sub("[^0-9]","",e)
        REGNO = input("Enter REGNO:")
        COLOR = input("Enter COLOR:")
        OWNER= input("Enter OWNER:")
        MODEL= input("Enter MODEL:")
        insert(ENGNUM,REGNO,COLOR,OWNER,MODEL)
    if ch == (3):
        exit
        
