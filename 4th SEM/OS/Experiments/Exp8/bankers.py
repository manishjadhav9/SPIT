
# 5  processes: P0, P1, P2, P3, P4
n = 5  # Number of processes: P0, P1, P2, P3, P4
m = 3  # Number of resources: A, B, C

# ALLOCATION COLUMN
alloc = [[0, 1, 0], [2, 0, 0],
         [3, 0, 2], [2, 1, 1], [0, 0, 2]]

# MAXIMUM COLUMN
max = [[7, 5, 3], [3, 2, 2],
       [9, 0, 2], [2, 2, 2], [4, 3, 3]]

# AVAILABLE COLUMN
avail = [3, 3, 2]  

# table display for output which includes process, allocation, max, available based on input values provided.
print("Process      Allocation           Max         Available")
for i in range(n):
    print(f"P{i}            {alloc[i]}        {max[i]}      {avail}")

f = [0] * n
ans = [0] * n
ind = 0
for k in range(n):
    f[k] = 0

need = [[0 for i in range(m)] for i in range(n)]
for i in range(n):
    for j in range(m):
        need[i][j] = max[i][j] - alloc[i][j]

# Display the Need Matrix
print("\nNeed Matrix:")
for i in range(n):
    print(need[i])

for k in range(5):
    for i in range(n):
        if f[i] == 0:
            flag = 0
            for j in range(m):
                if need[i][j] > avail[j]:
                    flag = 1
                    break

            if flag == 0:
                ans[ind] = i
                ind += 1
                for y in range(m):
                    avail[y] += alloc[i][y]
                f[i] = 1

print("\nThe safe sequence for the program is as follows:")
for i in range(n - 1):
    print(" P", ans[i], " ->", sep="", end="")
print(" P", ans[n - 1], sep="")