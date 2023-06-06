import socket
sockfd = socket.socket()
host = socket.gethostname()
port =  3515
sockfd.bind((host,port))

sockfd.listen(1)
while True:
    client, addr = sockfd.accept()
    print("Connected from", addr)
    String = client.recv(1024).decode()
    length = len(String)
    if(String == String[::1]):
        client.send("String is pallindrome with length".encode())
    else:
        client.send("String is not palindrome with length".encode())
    
    client.send(str(length).encode())
    client.close()