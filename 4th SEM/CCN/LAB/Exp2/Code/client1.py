import socket

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    paragraph = input("Enter a paragraph: ") + '\n'
    s.sendall(paragraph.encode('utf-8'))
    results = s.recv(1024).decode('utf-8')
    print(results)

