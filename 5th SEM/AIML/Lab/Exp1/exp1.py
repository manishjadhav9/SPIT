boat_side = "Right"
missionary_on_right = 3
cannibals_on_right = 3
missionary_on_left = 0
cannibals_on_left = 0

def print_state():
    print(f"Missionaries on left = {missionary_on_left} Cannibals on left = {cannibals_on_left}", end='')
    print(" |-----Boat| " if boat_side == "Right" else " |Boat-----| ", end='')
    print(f"Missionaries = {missionary_on_right} Cannibals on right = {cannibals_on_right}")

print_state()

while True:
    missionary = int(input(f"Enter number of Missionary in boat on {boat_side}: "))
    cannibals = int(input(f"Enter number of Cannibals in boat on {boat_side}: "))
    
    # Condition for peoples on boat should be 1 or 2 only.
    if (missionary + cannibals) not in [1, 2]:
        print("Invalid move: Total people in boat must be 1 or 2")
        continue
    
    if boat_side == "Right":
        if missionary > missionary_on_right or cannibals > cannibals_on_right:
            print("Invalid move: Not enough people on the right side")
            continue
        
        missionary_on_right -= missionary
        cannibals_on_right -= cannibals
        missionary_on_left += missionary
        cannibals_on_left += cannibals
        boat_side = "Left"
    else:  
        if missionary > missionary_on_left or cannibals > cannibals_on_left:
            print("Invalid move: Not enough people on the left side")
            continue
        
        missionary_on_right += missionary
        cannibals_on_right += cannibals
        missionary_on_left -= missionary
        cannibals_on_left -= cannibals
        boat_side = "Right"
    
    print_state()
    
    # These condition checks whether condition for win is not satisfied i.e. you loose
    if (missionary_on_right != 0 and missionary_on_right < cannibals_on_right) or \
       (missionary_on_left != 0 and missionary_on_left < cannibals_on_left):
        print("YOU LOSE")
        break
    
    # These condition checks whether condition for win is satisfied i.e. you win
    if missionary_on_left == 3 and cannibals_on_left == 3:
        print("YOU WIN")
        break

print("GAME OVER")