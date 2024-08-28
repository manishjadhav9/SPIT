boat_side = "Right"
mis_right = 3
can_right = 3
mis_left = 0
can_left = 0

def print_state():
    print(f"mis_left = {mis_left} can_left = {can_left}", end='')
    print(" |-----b| " if boat_side == "Right" else " |b-----| ", end='')
    print(f"mis = {mis_right} can_right = {can_right}")

print_state()

while True:
    missionary = int(input(f"number of Missionary in boat {boat_side}: "))
    cannibals = int(input(f"number of Cannibals in boat {boat_side}: "))
    
    if (missionary + cannibals) not in [1, 2]:
        print("Invalid move: Total people in boat must be 1 or 2")
        continue
    
    if boat_side == "Right":
        if missionary > mis_right or cannibals > can_right:
            print("Invalid move: Not enough people on the right side")
            continue
        
        mis_right -= missionary
        can_right -= cannibals
        mis_left += missionary
        can_left += cannibals
        boat_side = "Left"
    else:  
        if missionary > mis_left or cannibals > can_left:
            print("Invalid move: Not enough people on the left side")
            continue        
        mis_right += missionary
        can_right += cannibals
        mis_left -= missionary
        can_left -= cannibals
        boat_side = "Right"
    
    print_state()
    
    if (mis_right != 0 and mis_right < can_right) or \
       (mis_left != 0 and mis_left < can_left):
        print("YOU LOOSE THE MATCH")
        break
    
    if mis_left == 3 and can_left == 3:
        print("YOU WON THE MATCH")
        break

print("GAME ENDS")