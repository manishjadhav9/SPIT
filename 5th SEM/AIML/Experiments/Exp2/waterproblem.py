def water_jug_dfs(capacity_a, capacity_b, target):
    def dfs(x, y, path):
        if (x, y) in visited:
            return None
        
        visited.add((x, y))
        path = path + [(x, y)]

        print(f"Current state: ({x}, {y})")

        if x == target and y == 0:
            return path

        # Apply production rules
        # 1. Fill the 4-liter jug
        if x < 4:
            result = dfs(4, y, path)
            if result:
                return result
        
        # 2. Fill the 3-liter jug
        if y < 3:
            result = dfs(x, 3, path)
            if result:
                return result
        
        # 3. Pour some water out of the 4-liter jug
        if x > 0:
            for d in range(1, x + 1):
                result = dfs(x - d, y + d if y + d <= 3 else 3, path)
                if result:
                    return result
        
        # 4. Pour some water out of the 3-liter jug
        if y > 0:
            for d in range(1, y + 1):
                result = dfs(x + d if x + d <= 4 else 4, y - d, path)
                if result:
                    return result
        
        # 5. Empty the 4-liter jug on the ground
        if x > 0:
            result = dfs(0, y, path)
            if result:
                return result
        
        # 6. Empty the 3-liter jug on the ground
        if y > 0:
            result = dfs(x, 0, path)
            if result:
                return result
        
        # 7. Pour from 3-liter to 4-liter until 4-liter is full
        if x + y >= 4 and y > 0:
            result = dfs(4, y - (4 - x), path)
            if result:
                return result
        
        # 8. Pour from 4-liter to 3-liter until 3-liter is full
        if x + y >= 3 and x > 0:
            result = dfs(x - (3 - y), 3, path)
            if result:
                return result
        
        # 9. Pour all from 3-liter to 4-liter
        if x + y <= 4 and y > 0:
            result = dfs(x + y, 0, path)
            if result:
                return result
        
        # 10. Pour all from 4-liter to 3-liter
        if x + y <= 3 and x > 0:
            result = dfs(0, x + y, path)
            if result:
                return result
        
        # 11. Pour 2-liter from 3-liter to 4-liter
        if (x, y) == (0, 2):
            result = dfs(2, 0, path)
            if result:
                return result
        
        # 12. Empty 2-liter from 4-liter to ground
        if x == 2:
            result = dfs(0, y, path)
            if result:
                return result
///////////////////////////////
        return None

    visited = set()
    return dfs(0, 0, [])

def get_positive_int_input(prompt):
    while True:
        try:
            value = int(input(prompt))
            if value > 0:
                return value
            else:
                print("Please enter a positive integer.")
        except ValueError:
            print("Invalid input. Please enter a positive integer.")

def main():
    print("Water Jug Problem Solver using DFS")
    print("----------------------------------")

    print("Using predefined jug capacities: 4-liter and 3-liter")
    target = get_positive_int_input("Enter the target amount: ")

    print(f"\nSolving for: Jug A (4 liters), Jug B (3 liters), Target: {target} liters")
    print("Starting the DFS search...")

    solution = water_jug_dfs(4, 3, target)

    if solution:
        print("\nSolution found:")
        for step, (a, b) in enumerate(solution):
            print(f"Step {step}: ({a}, {b})")
    else:
        print("No solution found.")

if __name__ == "__main__":
    main()