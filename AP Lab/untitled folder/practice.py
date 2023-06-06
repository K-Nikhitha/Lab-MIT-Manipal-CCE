import re
line = "2PID2283"
m=re.match(r'\d\d\w\w\w\d\d\d\d',line)
if m:
    print("Y")
else:
    print("N")
