#include <stdio.h>

void sjf(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];
    int temp[n];

    // Copy burst times into temp array
    for (int i = 0; i < n; i++) {
        temp[i] = burst_time[i];
    }

    // Sort processes based on burst time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
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
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i],
waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    sjf(processes, n, burst_time);

    return 0;
}