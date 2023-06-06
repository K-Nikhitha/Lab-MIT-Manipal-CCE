def UpLowCase(str):
    up = 0
    low = 0
    for i in str:
        if i >= "A" and i <= "Z":
            up+=1
        elif i >= "a" and i <= "z":
            low+=1
    print("Upper Case:", up)
    print("Lower Case:", low)
    return 0


inp = input("Enter string:")
UpLowCase(inp)
