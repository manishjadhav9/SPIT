import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            if not data:
                break

            paragraph = data.decode('utf-8')
            num_chars = len(paragraph)
            num_words = len(paragraph.split())
            num_sentences = paragraph.count('.')

            results = f"Characters: {num_chars}\nWords: {num_words}\nSentences: {num_sentences}"
            conn.sendall(results.encode('utf-8'))

