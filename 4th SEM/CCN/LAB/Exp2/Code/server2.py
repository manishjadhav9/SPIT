import socket
import threading


HOST = '127.0.0.1'
PORT = 65432


def handle_client(conn, addr):
    print(f"Connected by {addr}")
    while True:
        data = conn.recv(1024).decode('utf-8')
        if not data:
            break

        paragraph = data
        num_chars = len(paragraph)
        num_words = len(paragraph.split())
        num_sentences = paragraph.count('.')

        results = f"Characters: {num_chars}\nWords: {num_words}\nSentences: {num_sentences}"
        conn.sendall(results.encode('utf-8'))
    conn.close()


def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        print(f"Server listening on port {PORT}")
        while True:
            conn, addr = s.accept()
            thread = threading.Thread(target=handle_client, args=(conn, addr))
            thread.start()


if __name__ == '__main__':
    start_server()
