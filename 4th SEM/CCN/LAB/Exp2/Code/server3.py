import socket
import threading

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on

clients = []
client_names = {}

def handle_client(conn, addr, name):
    global clients, client_names
    print(f'{name} connected from {addr}')
    broadcast(f'{name} has joined the chat!', name)
    while True:
        try:
            data = conn.recv(1024).decode()
            if not data:
                break
            message = f'{name}: {data}'
            broadcast(message, name)
        except ConnectionError:
            print(f'{name} disconnected unexpectedly')
            broadcast(f'{name} has left the chat!', name)
            clients.remove(conn)
            del client_names[conn]
            break
    conn.close()

def broadcast(message, sender):
    for client in clients:
        if client != sender:
            try:
                client.sendall(message.encode())
            except ConnectionError:
                print(f'Error sending message to {client_names[client]}')

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print(f'Server listening on {HOST}:{PORT}')
    while True:
        conn, addr = s.accept()
        name = conn.recv(1024).decode()
        client_names[conn] = name
        clients.append(conn)
        client_thread = threading.Thread(target=handle_client, args=(conn, addr, name))
        client_thread.start()

