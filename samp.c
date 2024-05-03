//INSERTION
// void printArray(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }


// int main()
// {
//     int arr[] = { 12, 11, 13, 5, 6 };
//     int n = sizeof(arr) / sizeof(arr[0]);

//     insertSort(arr, n);
//     printArray(arr, n);

//     return 0;
// }


//SELECTION
// void printArray(int arr[], int size)
// {
//     int i;
//     for (i=0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// // Driver program to test above functions
// int main()
// {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     selectSort(arr, n);
//     printf("Sorted array: \n");
//     printArray(arr, n);
//     return 0;
// }



//MERGE
// void printArray(int A[], int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         printf("%d ", A[i]);
//     printf("\n");
// }

// int main()
// {
//     int arr[] = { 12, 11, 13, 5, 6, 7 };
//     int arr_size = sizeof(arr) / sizeof(arr[0]);

//     printf("Given array is \n");
//     printArray(arr, arr_size);

//     mergeSort(arr, 0, arr_size - 1);

//     printf("\nSorted array is \n");
//     printArray(arr, arr_size);
//     return 0;
// }





//QUICK
// int main()
// {
//     int arr[] = { 10, 7, 8, 9, 1, 5 };
//     int n = sizeof(arr) / sizeof(arr[0]);
  
//     // Function call
//     quickSort(arr, 0, n - 1);
  
//   // Print the sorted array
//     printf("Sorted Array\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }



// Exp6 greedy prims and kruskal
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// void primsAlgorithm(int **graph, int vertices, int startNode) {
//     int parent[vertices];
//     int key[vertices];
//     int mstSet[vertices];

//     for (int i = 0; i < vertices; i++) {
//         key[i] = INT_MAX;
//         mstSet[i] = 0;
//     }

//     key[startNode] = 0;
//     parent[startNode] = -1;

//     for (int count = 0; count < vertices - 1; count++) {
//         int minKey = INT_MAX, minIndex;

//         for (int v = 0; v < vertices; v++) {
//             if (mstSet[v] == 0 && key[v] < minKey) {
//                 minKey = key[v];
//                 minIndex = v;
//             }
//         }

//         mstSet[minIndex] = 1;

//         for (int v = 0; v < vertices; v++) {
//             if (graph[minIndex][v] && mstSet[v] == 0 && graph[minIndex][v] < key[v]) {
//                 parent[v] = minIndex;
//                 key[v] = graph[minIndex][v];
//             }
//         }
//     }

//     printf("Edge \tWeight\n");
//     for (int i = 0; i < vertices; i++) {
//         if (i != startNode) {
//             printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
//         }
//     }
// }

// void dijkstraAlgorithm(int **graph, int vertices, int src) {
//     int dist[vertices];
//     int visited[vertices];

//     for (int i = 0; i < vertices; i++) {
//         dist[i] = INT_MAX;
//         visited[i] = 0;
//     }

//     dist[src] = 0;

//     for (int count = 0; count < vertices - 1; count++) {
//         int minDist = INT_MAX, minIndex;

//         for (int v = 0; v < vertices; v++) {
//             if (!visited[v] && dist[v] <= minDist) {
//                 minDist = dist[v];
//                 minIndex = v;
//             }
//         }

//         visited[minIndex] = 1;

//         for (int v = 0; v < vertices; v++) {
//             if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INT_MAX &&
//                 dist[minIndex] + graph[minIndex][v] < dist[v]) {
//                 dist[v] = dist[minIndex] + graph[minIndex][v];
//             }
//         }
//     }

//     printf("Vertex \tDistance from Source\n");
//     for (int i = 0; i < vertices; i++) {
//         printf("%d \t%d\n", i, dist[i]);
//     }
// }

// int main() {
//     int choice, vertices, src;

//     printf("Enter the number of vertices: ");
//     scanf("%d", &vertices);

//     int **graph = (int **)malloc(vertices * sizeof(int *));
//     for (int i = 0; i < vertices; i++) {
//         graph[i] = (int *)malloc(vertices * sizeof(int));
//     }

//     printf("Enter the adjacency matrix:\n");
//     for (int i = 0; i < vertices; i++) {
//         for (int j = 0; j < vertices; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     do {
//         printf("\nChoose an option:\n");
//         printf("1. Prim's Algorithm\n");
//         printf("2. Dijkstra's Algorithm\n");
//         printf("3. Exit\n");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter the starting node for Prim's Algorithm: ");
//                 scanf("%d", &src);
//                 if (src >= 0 && src < vertices) {
//                     primsAlgorithm(graph, vertices, src);
//                 } else {
//                     printf("Invalid starting node.\n");
//                 }
//                 break;
//             case 2:
//                 printf("Enter the source vertex for Dijkstra's Algorithm: ");
//                 scanf("%d", &src);
//                 if (src >= 0 && src < vertices) {
//                     dijkstraAlgorithm(graph, vertices, src);
//                 } else {
//                     printf("Invalid source vertex.\n");
//                 }
//                 break;
//             case 3:
//                 printf("Execution Completed\n");
//                 break;
//             default:
//                 printf("Invalid choice. Please enter again.\n");
//         }
//     } while (choice != 3);

//     for (int i = 0; i < vertices; i++) {
//         free(graph[i]);
//     }
//     free(graph);

//     return 0;
// }












//ASSEMBLY LINE SCHEDULING USER INPUT
// #include <stdio.h>

// #define NUM_STATIONS 5
// #define NUM_LINES 2

// int min(int a, int b) {
//     return (a < b) ? a : b;
// }

// int productAssembly(int a[][NUM_STATIONS], int t[][NUM_STATIONS - 1], int e[2], int x[2]) {
//     int f1[NUM_STATIONS], f2[NUM_STATIONS];

//     // Time taken to reach the first station at line 1
//     f1[0] = e[0] + a[0][0];

//     // Time taken to reach the first station at line 2
//     f2[0] = e[1] + a[1][0];

//     // Fill tables f1[] and f2[] using the given recursive relations
//     for (int j = 1; j < NUM_STATIONS; j++) {
//         f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j - 1] + a[0][j]);
//         f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j - 1] + a[1][j]);
//     }

//     // Display the table of line and cost for each line
//     printf("\nLine and Cost Table:\n");
//     printf("Station  Line 1 Cost  Line 2 Cost\n");

//     for (int i = 0; i < NUM_STATIONS; i++) {
//         printf("%8d %12d %12d\n", i + 1, f1[i], f2[i]);
//     }

//     // Consider exit times and return minimum
//     return min(f1[NUM_STATIONS - 1] + x[0], f2[NUM_STATIONS - 1] + x[1]);
// }

// int main() {

//     int a[NUM_LINES][NUM_STATIONS], t[NUM_LINES][NUM_STATIONS - 1], e[NUM_LINES], x[NUM_LINES];

//     // Input values for a
//     printf("Enter values for a:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("Line %d: ", i + 1);
//         for (int j = 0; j < NUM_STATIONS; j++) {
//             scanf("%d", &a[i][j]);
//         }
//     }

//     // Input values for t
//     printf("Enter values for t:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("Line %d: ", i + 1);
//         for (int j = 0; j < NUM_STATIONS - 1; j++) {
//             scanf("%d", &t[i][j]);
//         }
//     }

//     // Input values for e
//     printf("Enter values for e:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("", i + 1);
//         scanf("%d", &e[i]);
//     }

//     // Input values for x
//     printf("Enter values for x:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("", i + 1);
//         scanf("%d", &x[i]);
//     }

//     // Calculate and display the optimal time for completing the product
//     int optimalTime = productAssembly(a, t, e, x);
//     printf("\nOptimal Time for completing the product is: %d\n", optimalTime);

//     return 0;
// }






//MIN-MAX HARD CODED
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #define ARRAY_SIZE 100000
// // #define ARRAY_SIZE 10
// // Function prototypes
// void generateNumbers(int numbers[], int size);
// void minMaxDivideConquer(int numbers[], int start, int end, int *min, int *max);
// void minMaxNaive(int numbers[], int size, int *min, int *max);
// int main()
// {
//     FILE *p = fopen("minmax.csv", "w");
//     fprintf(p, "Number, Time (Divide & Conquer), Time (Naive), Min, Max\n");

//      //Hard-coded array with 10 values
//     int numbers[ARRAY_SIZE] = {54, 21, 87, 63, 91, 37, 20, 48, 66, 15};

//     int min_dc, max_dc, min_naive, max_naive;
//     printf("Number, Time (Divide & Conquer), Time (Naive), Min, Max\n");
//     for (int i = 10; i <= ARRAY_SIZE; i += 10)
//     {
//         clock_t start, end;

//         // Divide and Conquer
//         start = clock();
//         minMaxDivideConquer(numbers, 0, i - 1, &min_dc, &max_dc);
//         end = clock();
//         double time_dc = ((double)(end - start)) / CLOCKS_PER_SEC;
//         // Naive Approach
//         start = clock();
//         minMaxNaive(numbers, i, &min_naive, &max_naive);
//         end = clock();
//         double time_naive = ((double)(end - start)) / CLOCKS_PER_SEC;
//         printf("%d, %lf, %lf, %d, %d\n", i, time_dc, time_naive, min_dc, max_dc);
//         fprintf(p, "%d, %lf, %lf, %d, %d\n", i, time_dc, time_naive, min_dc, max_dc);
//     }
//     return 0;
// }
// void generateNumbers(int numbers[], int size)
// {
//     for (int i = 0; i < size; ++i)
//     {
//         numbers[i] = rand(); // Using rand() for simplicity
//     }
// }
// void minMaxDivideConquer(int numbers[], int start, int end, int *min, int *max)
// {
//     if (start == end)
//     {
//         *min = *max = numbers[start];
//         return;
//     }
//     int mid = (start + end) / 2;
//     int min_left, max_left, min_right, max_right;
//     minMaxDivideConquer(numbers, start, mid, &min_left, &max_left);
//     minMaxDivideConquer(numbers, mid + 1, end, &min_right, &max_right);
//     *min = (min_left < min_right) ? min_left : min_right;
//     *max = (max_left > max_right) ? max_left : max_right;
// }
// void minMaxNaive(int numbers[], int size, int *min, int *max)
// {
//     *min = *max = numbers[0];
//     for (int i = 1; i < size; ++i)
//     {
//         if (numbers[i] < *min)
//         {
//             *min = numbers[i];
//         }
//         else if (numbers[i] > *max)
//         {
//             *max = numbers[i];
//         }
//     }
// }


//exp8 backtracking
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define MAX_SIZE 20

// int board[MAX_SIZE]; // Array to store the positions of queens in N-Queens problem
// int solutionCount = 0; // Counter to keep track of the number of solutions found

// // Function to print a solution to the N-Queens problem
// void printNQueensSolution(int n);

// // Function to check if placing a queen at position (row, col) is safe
// bool isSafe(int row, int col);

// // Recursive function to solve the N-Queens problem
// void solveNQueens(int n, int row);

// // Function to print a subset of a set
// void printSubset(int set[], int size);

// // Recursive function to solve the Sum of Subsets problem
// void solveSubsetSum(int set[], int n, int targetSum, int index, int subset[], int subsetIndex);

// int main() {
//     int choice;
//     while (1) {
//         printf("\nChoose an option:\n");
//         printf("1. Solve N-Queens problem\n");
//         printf("2. Solve Sum of Subsets problem\n");
//         printf("3. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         if (choice == 1) {
//             int n = 4; // Number of queens (N) is set to 4
//             printf("\nN-Queens Solution(s):\n");
//             solveNQueens(n, 0);
//             printf("\nTotal solutions: %d\n", solutionCount);
//             solutionCount = 0;
//         } else if (choice == 2) {
//             int n = 5; // Number of elements in the set is set to 5
//             int set[MAX_SIZE] = {1, 2, 3, 4, 5}; // Elements of the set
//             int targetSum = 7; // Target sum is set to 7
//             int subset[MAX_SIZE];
//             printf("\nSubsets with sum equal to %d:\n", targetSum);
//             solveSubsetSum(set, n, targetSum, 0, subset, 0);
//         } else if (choice == 3) {
//             break;
//         } else {
//             printf("\nInvalid choice. Please try again.\n");
//         }
//     }
//     return 0;
// }

// void printNQueensSolution(int n) {
//     printf("[");
//     for (int i = 0; i < n - 1; i++) {
//         printf("%d, ", board[i]);
//     }
//     printf("%d]\n", board[n - 1]);
// }

// bool isSafe(int row, int col) {
//     // Check if there is a queen in the same column or in the diagonal positions
//     for (int i = 0; i < row; i++) {
//         if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
//             return false;
//         }
//     }
//     return true;
// }

// void solveNQueens(int n, int row) {
//     // If all queens are placed, print the solution
//     if (row == n) {
//         printNQueensSolution(n);
//         solutionCount++;
//         return;
//     }
//     // placing a queen in each column of the current row
//     for (int col = 0; col < n; col++) {
//         if (isSafe(row, col)) {
//             board[row] = col;
//             solveNQueens(n, row + 1);
//         }
//     }
// }

// void printSubset(int set[], int size) {
//     printf("{");
//     for (int i = 0; i < size - 1; i++) {
//         printf("%d, ", set[i]);
//     }
//     printf("%d}\n", set[size - 1]);
// }

// void solveSubsetSum(int set[], int n, int targetSum, int index, int subset[], int subsetIndex) {
//     if (index == n) {
//         int sum = 0;
//         for (int i = 0; i < subsetIndex; i++) {
//             sum += subset[i];
//         }
//         if (sum == targetSum) {
//             printSubset(subset, subsetIndex);
//         }
//         return;
//     }
//     subset[subsetIndex] = set[index];
//     solveSubsetSum(set, n, targetSum, index + 1, subset, subsetIndex + 1);
//     solveSubsetSum(set, n, targetSum, index + 1, subset, subsetIndex);
// }


//graphcoloring
// #include <stdio.h>
// #include <stdbool.h>

// #define MAX_VERTICES 5

// int vertices = 5;  // Number of vertices
// int edges = 5;     // Number of edges
// int graph[MAX_VERTICES][MAX_VERTICES] = {
//     {0, 1, 1, 0, 1},
//     {1, 0, 1, 1, 0},
//     {1, 1, 0, 1, 0},
//     {0, 1, 1, 0, 1},
//     {1, 0, 0, 1, 0}
// };  // Adjacency matrix representing the graph
// int colors[MAX_VERTICES];

// // Function to check if it's safe to assign color 'c' to vertex 'v'
// bool isSafe(int v, int c) {
//     for (int i = 0; i < vertices; i++) {
//         // Check if there is an edge between 'v' and 'i' and if the color of 'i' is 'c'
//         if (graph[v][i] && c == colors[i]) {
//             return false;  // If the condition is true, it's not safe to assign 'c' to 'v'
//         }
//     }
//     return true;  // It's safe to assign 'c' to 'v'
// }

// // Recursive function to perform graph coloring using backtracking
// bool graphColoringUtil(int v, int m) {
//     // If all vertices are assigned colors, return true
//     if (v == vertices) {
//         return true;
//     }

//     // Try assigning colors to 'v'
//     for (int c = 1; c <= m; c++) {
//         // Check if it's safe to assign color 'c' to vertex 'v'
//         if (isSafe(v, c)) {
//             colors[v] = c;  // Assign color 'c' to vertex 'v'

//             // Recur to assign colors to the rest of the vertices
//             if (graphColoringUtil(v + 1, m)) {
//                 return true;  // If coloring is possible, return true
//             }

//             colors[v] = 0;  // Backtrack: Remove color assignment if coloring is not possible
//         }
//     }

//     return false;  // If no color can be assigned to this vertex, return false
// }

// // Main function to perform graph coloring
// bool graphColoring(int m) {
//     // Call the utility function with vertex 0 and m colors
//     if (!graphColoringUtil(0, m)) {
//         printf("No solution exists\n");
//         return false;
//     }

//     printf("The graph can be colored using %d colors as follows:\n", m);
//     for (int i = 0; i < vertices; i++) {
//         printf("Vertex %d: Color %d\n", i, colors[i]);
//     }

//     return true;
// }

// int main() {
//     // Hardcoded number of colors available
//     int m = 3;

//     // Perform graph coloring
//     graphColoring(m);

//     return 0;
// }



//branch and bound
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #define N 4
// typedef struct PuzzleNode
// {
//   int state[N][N];
//   struct PuzzleNode *parent;
//   char action;
//   int cost;
// } PuzzleNode;

// // Define a stack structure for storing states
// typedef struct Stack
// {
//   PuzzleNode *items[10000];
//   int top;
// } Stack;

// // Function to initialize the stack
// void initializeStack(Stack *stack)
// {
//   stack->top = -1;
// }

// // Function to push an item onto the stack
// void push(Stack *stack, PuzzleNode *item)
// {
//   stack->items[++stack->top] = item;
// }

// // Function to pop an item from the stack
// PuzzleNode *pop(Stack *stack)
// {
//   return stack->items[stack->top--];
// }

// // Function to create a new PuzzleNode
// PuzzleNode *createNode(int state[N][N], PuzzleNode *parent, char action, int cost)
// {
//   PuzzleNode *newNode = (PuzzleNode *)malloc(sizeof(PuzzleNode));
//   if (newNode == NULL)
//   {
//     printf("Memory allocation failed.\n");
//     exit(1);
//   }
//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < N; j++)
//     {
//       newNode->state[i][j] = state[i][j];
//     }
//   }
//   newNode->parent = parent;
//   newNode->action = action;
//   newNode->cost = cost;
//   return newNode;
// }

// // Function to check if the current state is the goal state
// bool isGoalState(int state[N][N], int goalState[N][N])
// {
//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < N; j++)
//     {
//       if (state[i][j] != goalState[i][j])
//       {
//         return false;
//       }
//     }
//   }
//   return true;
// }

// // Function to print the state of the puzzle
// void printState(int state[N][N])
// {
//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < N; j++)
//     {
//       printf("%d ", state[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
// }

// // Function to swap two tiles in the state matrix
// void swap(int state[N][N], int i1, int j1, int i2, int j2)
// {
//   int temp = state[i1][j1];
//   state[i1][j1] = state[i2][j2];
//   state[i2][j2] = temp;
// }

// // Function to find the position of the blank tile in the state matrix
// void findBlankPosition(int state[N][N], int *blankRow, int *blankCol)
// {
//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < N; j++)
//     {
//       if (state[i][j] == 0)
//       {
//         *blankRow = i;
//         *blankCol = j;
//         return;
//       }
//     }
//   }
// }

// // Function to perform the Branch and Bound algorithm using FIFO strategy
// void solveFIFO(int initialState[N][N], int goalState[N][N])
// {
//   // Queue to store the PuzzleNodes
//   PuzzleNode *queue[10000];
//   int front = 0, rear = 0;
//   queue[rear++] = createNode(initialState, NULL, '\0', 0);
//   // Initialize a stack to store states
//   Stack stack;
//   initializeStack(&stack);
//   while (front < rear)
//   {
//     PuzzleNode *currentNode = queue[front++];
//     int blankRow, blankCol;
//     findBlankPosition(currentNode->state, &blankRow, &blankCol);
//     // Check if the current state is the goal state
//     if (isGoalState(currentNode->state, goalState))
//     {
//       // Push the solution path onto the stack
//       while (currentNode != NULL)
//       {
//         push(&stack, currentNode);
//         currentNode = currentNode->parent;
//       }
//       // Pop and print the states from the stack to reverse the order
//       while (stack.top != -1)
//       {
//         currentNode = pop(&stack);
//         printState(currentNode->state);
//       }
//       return;
//     }
//     // Move the blank tile up
//     if (blankRow > 0)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'U', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow - 1, blankCol);
//       queue[rear++] = newNode;
//     }
//     if (blankRow < N - 1)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'D', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow + 1, blankCol);
//       queue[rear++] = newNode;
//     }
//     // Move the blank tile left
//     if (blankCol > 0)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'L', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow, blankCol - 1);
//       queue[rear++] = newNode;
//     }
//     // Move the blank tile right
//     if (blankCol < N - 1)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'R', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow, blankCol + 1);
//       queue[rear++] = newNode;
//     }
//   }
// }

// void solveLC(int initialState[N][N], int goalState[N][N])
// {
//   PuzzleNode *priorityQueue[10000];
//   int front = 0, rear = 0;
//   priorityQueue[rear++] = createNode(initialState, NULL, '\0', 0);
//   Stack stack;
//   initializeStack(&stack);

//   while (front < rear)
//   {
//     PuzzleNode *currentNode = priorityQueue[front++];
//     int blankRow, blankCol;
//     findBlankPosition(currentNode->state, &blankRow, &blankCol);
//     if (isGoalState(currentNode->state, goalState))
//     {
//       while (currentNode != NULL)
//       {
//         push(&stack, currentNode);
//         currentNode = currentNode->parent;
//       }
//       while (stack.top != -1)
//       {
//         currentNode = pop(&stack);
//         printState(currentNode->state);
//       }
//       return;
//     }

//     if (blankRow > 0)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'U', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow - 1, blankCol);
//       priorityQueue[rear++] = newNode;
//     }
//     // Move the blank tile down
//     if (blankRow < N - 1)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'D', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow + 1, blankCol);
//       priorityQueue[rear++] = newNode;
//     }
//     // Move the blank tile left
//     if (blankCol > 0)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'L', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow, blankCol - 1);
//       priorityQueue[rear++] = newNode;
//     }
//     // Move the blank tile right
//     if (blankCol < N - 1)
//     {
//       PuzzleNode *newNode = createNode(currentNode->state, currentNode, 'R', currentNode->cost + 1);
//       swap(newNode->state, blankRow, blankCol, blankRow, blankCol + 1);
//       priorityQueue[rear++] = newNode;
//     }
//   }
// }
// int main()
// {
//   int initialState[N][N] = {{1, 2, 3, 4},
//                              {5, 6, 7, 8},
//                              {9, 10, 11, 12},
//                              {13, 14, 15, 0}};
//   int goalState[N][N] = {{1, 2, 3, 4},
//                           {5, 6, 7, 8},
//                           {9, 10, 11, 12},
//                           {13, 14, 15, 0}};

//   int choice;
//   printf("Choose the strategy:\n");
//   printf("1. FIFO\n");
//   printf("2. Least Cost\n");
//   printf("Enter your choice: ");
//   scanf("%d", &choice);
//   switch (choice)
//   {
//   case 1:
//     printf("\nUsing FIFO Strategy:\n");
//     solveFIFO(initialState, goalState);
//     break;
//   case 2:
//     printf("\nUsing Least Cost Strategy:\n");
//     solveLC(initialState, goalState);
//     break;
//   default:
//     printf("Invalid choice.\n");
//     break;
//   }
//   return 0;
// }
