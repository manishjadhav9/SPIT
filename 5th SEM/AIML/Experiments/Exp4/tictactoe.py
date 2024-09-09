import math

def print_board(board):
    for i in range(3):
        print(" | ".join(board[i*3:(i+1)*3]))
        if i < 2:
            print("---------")

def empty_cells(board):
    return [i for i, cell in enumerate(board) if cell == " "]

def is_winner(board, player):
    winning_combinations = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
        [0, 4, 8], [2, 4, 6]  # Diagonals
    ]
    return any(all(board[i] == player for i in combo) for combo in winning_combinations)

def game_over(board):
    return is_winner(board, "X") or is_winner(board, "O") or len(empty_cells(board)) == 0

def minimax(board, depth, is_maximizing):
    if is_winner(board, "X"):
        return -1
    if is_winner(board, "O"):
        return 1
    if len(empty_cells(board)) == 0:
        return 0

    if is_maximizing:
        best_score = -math.inf
        for move in empty_cells(board):
            board[move] = "O"
            score = minimax(board, depth + 1, False)
            board[move] = " "
            best_score = max(score, best_score)
        return best_score
    else:
        best_score = math.inf
        for move in empty_cells(board):
            board[move] = "X"
            score = minimax(board, depth + 1, True)
            board[move] = " "
            best_score = min(score, best_score)
        return best_score

def get_best_move(board):
    best_score = -math.inf
    best_move = None
    for move in empty_cells(board):
        board[move] = "O"
        score = minimax(board, 0, False)
        board[move] = " "
        if score > best_score:
            best_score = score
            best_move = move
    return best_move

def get_player_move(board, player):
    while True:
        try:
            move = int(input(f"Player {player}, enter your move (0-8): "))
            if move not in empty_cells(board):
                raise ValueError
            return move
        except ValueError:
            print("Invalid move. Try again.")

def play_game(mode):
    board = [" " for _ in range(9)]
    current_player = "X"
    
    if mode == "1":
        print("You are X, AI is O")
    else:
        print("Player 1: X, Player 2: O")
    
    print_board(board)

    while not game_over(board):
        if mode == "1" and current_player == "O":
            print("AI is making a move...")
            move = get_best_move(board)
        else:
            move = get_player_move(board, current_player)
        
        board[move] = current_player
        print_board(board)

        if game_over(board):
            break

        current_player = "O" if current_player == "X" else "X"

    if is_winner(board, "X"):
        print("X wins!")
    elif is_winner(board, "O"):
        print("O wins!")
    else:
        print("It's a tie!")

def main():
    print("Welcome to Tic Tac Toe!")
    while True:
        mode = input("Enter 1 for single player (vs AI) or 2 for two players: ")
        if mode in ["1", "2"]:
            break
        print("Invalid input. Please enter 1 or 2.")
    
    play_game(mode)

if __name__ == "__main__":
    main()