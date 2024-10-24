#include<stdio.h>
void sortProcessByArrivalAndBurstTime(int processes[],int n,int at[],int bt[])
{
    for(int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(at[i]>at[j] || (at[i]==at[j] && bt[i]>bt[j]))
            {
                int temp=bt[i];
                bt[i]=bt[j];
                bt[j]=bt[i];
                
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}
void findCompletionTime(int processes[],int n,int at[],int bt[],int ct[])
{
   int ctime=0;
    for(int i=0;i<n;i++)
    {
        if(ctime<at[i])
        {
            ctime=at[i];
        }
        ctime=ctime+bt[i];
        ct[i]=ctime;
    }
}
void findTurnAroundTime(int processes[],int n,int at[],int ct[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
    }
}
void findWaitingTime(int processes[],int n,int bt[],int tat[],int wt[])
{
    for(int i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
    }
}
void findAverageTime(int processes[],int n,int bt[],int at[])
{
    int ct[n],tat[n],wt[n];
    findCompletionTime(processes, n, at, bt, ct);
    findTurnAroundTime(processes, n,  at, ct, tat);
    findWaitingTime(processes, n, bt, tat, wt);
    int totaltat=0,totalwt=0;
    for (int i = 0; i < n; i++)
    {
        totaltat=totaltat+tat[i];
        totalwt=totalwt+wt[i];
        
    }
    float avgwt=(float)totalwt/n;
    float avgtat=(float)totaltat/n;
    printf("ProcessId\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
         printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Waiting Time:%f\n",avgwt);
    printf("Average TurnAround Time:%f\n",avgtat);
    
}
    
int main()
{
    int n;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    int processes[n],at[n],bt[n];
    printf("enter the arrival time and burst time\n");
    for(int i=0;i<n;i++)
    {
        processes[i]=i+1;
        printf("Process %d\n",i+1);
        printf("Burst time:");
        scanf("%d",&bt[i]);
        printf("Arrival time:");
        scanf("%d",&at[i]);
        
    }
    sortProcessByArrivalAndBurstTime(processes,n,bt,at);
    findAverageTime(processes,n,bt,at);
    
}
