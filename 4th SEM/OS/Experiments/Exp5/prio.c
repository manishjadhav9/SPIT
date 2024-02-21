#include <stdio.h>

void priority_alo(int processes[], int n, int burst_time[], int priority[]) {
    int waiting_time[n], turnaround_time[n];
    int temp[n];

    // Copy burst times and priorities into temp arrays
    for (int i = 0; i < n; i++) {
        temp[i] = burst_time[i];
    }

    // Sort processes based on priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                int t = priority[i];
                priority[i] = priority[j];
                priority[j] = t;

                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                t = processes[i];
                processes[i] = processes[j];
                processes[j] = t;
            }
        }
    }

    // Calculate waiting time
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = temp[i - 1] + waiting_time[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = temp[i] + waiting_time[i];
    }

    // Display results
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i],
burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];
    int priority[n];

    // Input burst time and priority for each process
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    priority_alo(processes, n, burst_time, priority);

    return 0;
}