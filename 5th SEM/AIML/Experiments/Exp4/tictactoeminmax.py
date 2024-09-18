def print_board(board):
    for i in range(3):
        print(" ".join(board[i*3:(i+1)*3]))
    print()

def check_winner(board):
    # Check rows, columns and diagonals
    winning_combinations = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
        [0, 4, 8], [2, 4, 6]  # Diagonals
    ]
    for combo in winning_combinations:
        if board[combo[0]] == board[combo[1]] == board[combo[2]] != ' ':
            return board[combo[0]]
    if ' ' not in board:
        return 'Tie'
    return None

def minimax(board, depth, is_maximizing):
    result = check_winner(board)
    if result == 'X':
        return 1
    elif result == 'O':
        return -1
    elif result == 'Tie':
        return 0

    if is_maximizing:
        best_score = float('-inf')
        for i in range(9):
            if board[i] == ' ':
                board[i] = 'X'
                score = minimax(board, depth + 1, False)
                board[i] = ' '
                best_score = max(score, best_score)
        return best_score
    else:
        best_score = float('inf')
        for i in range(9):
            if board[i] == ' ':
                board[i] = 'O'
                score = minimax(board, depth + 1, True)
                board[i] = ' '
                best_score = min(score, best_score)
        return best_score

def best_move(board):
    best_score = float('-inf')
    move = -1
    for i in range(9):
        if board[i] == ' ':
            board[i] = 'X'
            score = minimax(board, 0, False)
            board[i] = ' '
            if score > best_score:
                best_score = score
                move = i
    return move

def play_game():
    board = [' ' for _ in range(9)]
    print("Initial board:")
    print_board(board)

    while True:
        move = best_move(board)
        board[move] = 'X'
        print("AI's move:")
        print_board(board)

        if check_winner(board):
            break

        player_move = int(input("Enter your move (0-8): "))
        board[player_move] = 'O'
        print("Your move:")
        print_board(board)

        if check_winner(board):
            break

    result = check_winner(board)
    if result == 'X':
        print("AI wins!")
    elif result == 'O':
        print("You win!")
    else:
        print("It's a tie!")

if __name__ == "__main__":
    play_game()