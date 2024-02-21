#include <stdio.h>

void fcfs(int process[], int n, int burst_time[])
{
  int waiting_time[n], turnaround_time[n];
  waiting_time[0] = 0; // Waiting time for the first process is 0

  // Calculate waiting time
  for (int i = 1; i < n; i++)
  {
    waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
  }

  // Calculate turnaround time
  for (int i = 0; i < n; i++)
  {
    turnaround_time[i] = waiting_time[i] + burst_time[i];
  }

  // Display results
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i],
           waiting_time[i], turnaround_time[i]);
  }
}

int main()
{
  int n;

  printf("Enter the number of process: ");
  scanf("%d", &n);

  int process[n];
  int burst_time[n];

  // Input burst time for each process
  for (int i = 0; i < n; i++)
  {
    process[i] = i + 1;
    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
  }

  fcfs(process, n, burst_time);

  return 0;
}