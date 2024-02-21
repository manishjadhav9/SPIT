#include <stdio.h>

void roundRobin(int processes[], int n, int burst_time[], int quantum) {
    int remaining_burst_time[n];
    int waiting_time[n], turnaround_time[n];

    // Copy burst times into remaining_burst_time array
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    int t = 0; // Current time
    int done = 0; // Flag to indicate if all processes are done

    // Keep traversing processes in round robin manner until all done
    while (!done) {
        done = 1; // Assume all processes are done

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0; // At least one process is not done

                // If burst time is greater than quantum
                if (remaining_burst_time[i] > quantum) {
                    t += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    t = t + remaining_burst_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    // Display results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i],
waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int processes[n];
    int burst_time[n];

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    roundRobin(processes, n, burst_time, quantum);

    return 0;
}