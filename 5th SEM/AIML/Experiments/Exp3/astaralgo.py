import heapq

class Node:
    def __init__(self, state, parent=None, g=0, h=0):
        self.state = state
        self.parent = parent
        self.g = g
        self.h = h
        self.f = g + h

    def __lt__(self, other):
        return self.f < other.f

def astar_search(graph, start, goal, heuristic):
    start_node = Node(start, None, 0, heuristic[start])
    frontier = []
    heapq.heappush(frontier, start_node)
    explored = set()
    step = 1

    while frontier:
        current_node = heapq.heappop(frontier)

        print(f"\nStep {step}:")
        print(f"Current node: {current_node.state}")
        print(f"f(n) = {current_node.f}, g(n) = {current_node.g}, h(n) = {current_node.h}")

        if current_node.state == goal:
            path = []
            while current_node:
                path.append(current_node.state)
                current_node = current_node.parent
            return list(reversed(path))

        explored.add(current_node.state)
        print(f"Explored set: {explored}")

        for neighbor, cost in graph[current_node.state].items():
            if neighbor not in explored:
                g = current_node.g + cost
                h = heuristic[neighbor]
                new_node = Node(neighbor, current_node, g, h)

                if new_node not in frontier:
                    heapq.heappush(frontier, new_node)
                    print(f"Added to frontier: {neighbor} (f={new_node.f}, g={g}, h={h})")
                else:
                    for i, node in enumerate(frontier):
                        if node.state == neighbor and node.g > g:
                            frontier[i] = new_node
                            heapq.heapify(frontier)
                            print(f"Updated in frontier: {neighbor} (f={new_node.f}, g={g}, h={h})")
                            break

        print("Frontier:", [(node.state, node.f) for node in frontier])
        step += 1

    return None

# Romania map values 
romania_map = {
    'Arad': {'Zerind': 75, 'Sibiu': 140, 'Timisoara': 118},
    'Zerind': {'Arad': 75, 'Oradea': 71},
    'Oradea': {'Zerind': 71, 'Sibiu': 151},
    'Sibiu': {'Arad': 140, 'Oradea': 151, 'Fagaras': 99, 'Rimnicu Vilcea': 80},
    'Timisoara': {'Arad': 118, 'Lugoj': 111},
    'Lugoj': {'Timisoara': 111, 'Mehadia': 70},
    'Mehadia': {'Lugoj': 70, 'Drobeta': 75},
    'Drobeta': {'Mehadia': 75, 'Craiova': 120},
    'Craiova': {'Drobeta': 120, 'Rimnicu Vilcea': 146, 'Pitesti': 138},
    'Rimnicu Vilcea': {'Sibiu': 80, 'Craiova': 146, 'Pitesti': 97},
    'Fagaras': {'Sibiu': 99, 'Bucharest': 211},
    'Pitesti': {'Rimnicu Vilcea': 97, 'Craiova': 138, 'Bucharest': 101},
    'Bucharest': {'Fagaras': 211, 'Pitesti': 101, 'Giurgiu': 90, 'Urziceni': 85},
    'Giurgiu': {'Bucharest': 90},
    'Urziceni': {'Bucharest': 85, 'Vaslui': 142, 'Hirsova': 98},
    'Hirsova': {'Urziceni': 98, 'Eforie': 86},
    'Eforie': {'Hirsova': 86},
    'Vaslui': {'Urziceni': 142, 'Iasi': 92},
    'Iasi': {'Vaslui': 92, 'Neamt': 87},
    'Neamt': {'Iasi': 87}
}

# heuristic values
heuristic = {
    'Arad': 366, 'Bucharest': 0, 'Craiova': 160, 'Drobeta': 242, 'Eforie': 161,
    'Fagaras': 176, 'Giurgiu': 77, 'Hirsova': 151, 'Iasi': 226, 'Lugoj': 244,
    'Mehadia': 241, 'Neamt': 234, 'Oradea': 380, 'Pitesti': 100, 'Rimnicu Vilcea': 193,
    'Sibiu': 253, 'Timisoara': 329, 'Urziceni': 80, 'Vaslui': 199, 'Zerind': 374
}

# Get user input for start and goal cities
print("Available cities:", ', '.join(romania_map.keys()))
start = input("Enter the start city: ")
goal = input("Enter the goal city: ")

if start not in romania_map or goal not in romania_map:
    print("Invalid start or goal city. Please choose from the available cities.")
else:
    path = astar_search(romania_map, start, goal, heuristic)
    if path:
        print(f"\nPath found: {' -> '.join(path)}")
        print(f"Total cost: {sum(romania_map[path[i]][path[i+1]] for i in range(len(path)-1))}")
    else:
        print("No path found")