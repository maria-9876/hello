#include<stdio.h>
void sortProcesses(int processes[],int n, int at[], int bt[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] ||
                (at[i] == at[j] && priority[i] >priority[j])) {
                // Swap process number
                int temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;

                // Swap arrival time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
}
void findCompletionTime(int processes[],int n,int at[],int bt[],int priority[],int ct[])
{
   
int servicetime = 0;
    for (int i = 0; i < n; i++) {
        if (servicetime < at[i]) {
            servicetime = at[i];
        }
        servicetime += bt[i];
        ct[i] = servicetime;
    }
}
void findTurnAroundTime(int processes[],int n,int ct[],int at[],int tat[])
{
     for (int i = 0; i < n; i++)
     {
        tat[i] = ct[i] - at[i];
    }
}
void findWaitingTime(int processes[],int n,int bt[],int tat[],int wt[])
{
     for (int i = 0; i < n; i++)
     {
        wt[i] = tat[i] - bt[i];
    }
}
    void findAverageTime(int processes[], int n, int bt[], int at[], int priority[]) {
    int ct[n], tat[n], wt[n];

    findCompletionTime(processes, n,  at,bt, priority, ct);
    findTurnAroundTime(processes, n, ct,at, tat);
    findWaitingTime(processes, n, bt, tat, wt);
    int totalwt=0,totaltat=0;
     for (int i = 0; i < n; i++)
     {
        totalwt=totalwt+wt[i];
        totaltat=totaltat+tat[i];
    }
    float avgwt=(float)totalwt/n;
    float avgtat=(float)totaltat/n;
     printf("Process\tBurst Time\tArrival Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], priority[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);
}
int main()
{
    int n;
    printf("Enter the no of processes\n");
    scanf("%d",&n);
    int processes[n],bt[n],at[n],priority[n];
    for(int i=0;i<n;i++)
    {
        processes[i]=i+1;
        printf("Process %d:\n",i+1);
        printf("BurstTime:\n");
        scanf("%d",&bt[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    sortProcesses(processes,n, at, bt, priority);
    findAverageTime(processes,n,bt,at,priority);
    return 0;
}
