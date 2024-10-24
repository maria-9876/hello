#include <stdio.h>

void findCompletionTime(int processes[], int n, int at[], int bt[], int ct[], int quantum) {
    int rt[n];  // Remaining time of each process
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
    int time = 0;  // Current time
    int counter = n;  // Number of processes left to complete

    while (counter != 0) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= quantum) {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    counter--;
                } else {
                    rt[i] -= quantum;
                    time += quantum;
                }
            }
        }
    }
}

void findTurnAroundTime(int processes[], int n, int at[], int ct[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }
}

void findWaitingTime(int processes[], int n, int bt[], int tat[], int wt[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[], int at[], int quantum) {
    int ct[n], tat[n], wt[n];
    findCompletionTime(processes, n, at, bt, ct, quantum);
    findTurnAroundTime(processes, n, at, ct, tat);
    findWaitingTime(processes, n, bt, tat, wt);

    int totalTat = 0, totalWt = 0;
    for (int i = 0; i < n; i++) {
        totalTat += tat[i];
        totalWt += wt[i];
    }

    float avgWt = (float) totalWt / n;
    float avgTat = (float) totalTat / n;

    printf("Process\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Waiting Time: %.2f\n", avgWt);
    printf("Average Turnaround Time: %.2f\n", avgTat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n], bt[n], at[n];
    int quantum;

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findAverageTime(processes, n, bt, at, quantum);
    return 0;
}
