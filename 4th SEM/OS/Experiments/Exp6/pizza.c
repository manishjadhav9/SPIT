#include <stdio.h>
#include <stdlib.h>

// Struct to represent a pizza order
typedef struct {
    int id; // Pizza order ID
    int prep_time; // Preparation time in minutes
    int delivery_distance; // Delivery distance in kilometers
    int priority; // Priority level (1 = highest, 5 = lowest)
} PizzaOrder;

// Struct to represent a delivery driver
typedef struct {
    int id; // Driver ID
    int time_left; // Time left for current delivery
} DeliveryDriver;

// Function prototypes
void fcfs(PizzaOrder orders[], int num_orders);
void sjf(PizzaOrder orders[], int num_orders);
void round_robin(PizzaOrder orders[], int num_orders, int time_quantum);
void priority(PizzaOrder orders[], int num_orders);

int main() {
    int num_orders, num_drivers, time_quantum;

    // Get number of pizza orders
    printf("Enter the number of pizza orders: ");
    scanf("%d", &num_orders);

    // Allocate memory for pizza orders
    PizzaOrder *orders = malloc(num_orders * sizeof(PizzaOrder));

    // Get pizza order details
    for (int i = 0; i < num_orders; i++) {
        printf("Enter details for pizza order %d:\n", i + 1);
        orders[i].id = i + 1;
        printf("Preparation time (in minutes): ");
        scanf("%d", &orders[i].prep_time);
        printf("Delivery distance (in kilometers): ");
        scanf("%d", &orders[i].delivery_distance);
        printf("Priority level (1 = highest, 5 = lowest): ");
        scanf("%d", &orders[i].priority);
    }

    // Get number of delivery drivers
    printf("\nEnter the number of delivery drivers: ");
    scanf("%d", &num_drivers);

    // Allocate memory for delivery drivers
    DeliveryDriver *drivers = malloc(num_drivers * sizeof(DeliveryDriver));

    // Initialize delivery drivers
    for (int i = 0; i < num_drivers; i++) {
        drivers[i].id = i + 1;
        drivers[i].time_left = 0;
    }

    // Get time quantum for Round Robin scheduling
    printf("\nEnter the time quantum for Round Robin scheduling: ");
    scanf("%d", &time_quantum);

    // Call scheduling algorithms
    fcfs(orders, num_orders);
    sjf(orders, num_orders);
    round_robin(orders, num_orders, time_quantum);
    priority(orders, num_orders);

    // Free allocated memory
    free(orders);
    free(drivers);

    return 0;
}

//FCFS
void fcfs(PizzaOrder orders[], int num_orders) {
    printf("\nFCFS Scheduling\n");
    for (int i = 0; i < num_orders; i++) {
        printf("Delivering pizza order %d\n", orders[i].id);
    }
}

// Shortest job first
void sjf(PizzaOrder orders[], int num_orders) {
    printf("\nSJF Scheduling\n");
    for (int i = 0; i < num_orders - 1; i++) {
        for (int j = 0; j < num_orders - i - 1; j++) {
            if (orders[j].prep_time + orders[j].delivery_distance >
                orders[j + 1].prep_time + orders[j + 1].delivery_distance) {
                // Swap orders
                PizzaOrder temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < num_orders; i++) {
        printf("Delivering pizza order %d\n", orders[i].id);
    }
}

// Round-Robin
void round_robin(PizzaOrder orders[], int num_orders, int time_quantum) {
    printf("\nRound Robin Scheduling\n");
    int remaining_orders = num_orders;
    int current_order = 0;
    while (remaining_orders > 0) {
        for (int i = 0; i < num_orders; i++) {
            if (orders[i].prep_time > 0) {
                printf("Delivering pizza order %d\n", orders[i].id);
                if (orders[i].prep_time > time_quantum) {
                    orders[i].prep_time -= time_quantum;
                } else {
                    orders[i].prep_time = 0;
                    remaining_orders--;
                }
            }
        }
    }
}

//Priority
void priority(PizzaOrder orders[], int num_orders) {
    printf("\nPriority Scheduling\n");
    // Sort orders based on priority level (highest to lowest)
    for (int i = 0; i < num_orders - 1; i++) {
        for (int j = 0; j < num_orders - i - 1; j++) {
            if (orders[j].priority > orders[j + 1].priority) {
                // Swap orders
                PizzaOrder temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
    
    // Print the order of delivery
    for (int i = 0; i < num_orders; i++) {
        printf("Delivering pizza order %d\n", orders[i].id);
    }
}
