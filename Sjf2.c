//SHORTEST JOB FIRST with ARRIVAL TIME
#include <stdio.h>
struct processes
{
    int id;
    int bt;
    int at;
    int ct;
    int tat;
    int wt;
};

int main()
{
    int n,i,j,sumtat=0,sumwt=0,ct=0;
    float avgtat=0,avgwt=0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    struct processes process[n],temp; 
    printf("Enetr the process id,arrival time and the burst time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&process[i].id,&process[i].at,&process[i].bt);
    }
    //arranging the process in ascending order of arrival time
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            if(process[i].at>process[i+1].at)
            {
                temp=process[i];
                process[i]=process[i+1];
                process[i+1]=temp;
            }
        }
    }
    
    //finding the order of executing the process
    int min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(process[j].bt<process[min].bt&&process[j].at<=ct)
            {
                min=j;
            }
        }
        ct=ct+process[min].bt;
        temp=process[i];
        process[i]=process[min];
        process[min]=temp;
        
    }
    //finding the tat,wt
    ct=process[0].at;
        process[0].ct=process[0].bt;
        process[0].tat=process[0].ct-process[0].at;
        process[0].wt=process[0].tat-process[0].bt;
    for(i=1;i<n;i++)
    {
        process[i].ct=process[i].bt+process[i-1].ct;
        process[i].tat=process[i].ct-process[i].at;
        process[i].wt=process[i].tat-process[i].bt;
        sumtat=sumtat+process[i].tat;
        sumwt=sumwt+process[i].wt;
    }

      
    //arranging the process according to their id
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            if(process[i].id>process[i+1].id)
            {
                temp=process[i];
                process[i]=process[i+1];
                process[i+1]=temp;
            }
        }
    }
    //finding average wt and tat
    avgtat=(float)sumtat/n;
    avgwt=(float)sumwt/n;
    
    //printing the details
    printf("------SHORTEST JOB FIRST------\n");
    printf("\nPID\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",process[i].id,process[i].bt,process[i].ct,process[i].tat,process[i].wt);
    }
    printf("AVERAGE WAITING TIME:%f\n",avgwt);
    printf("AVERAGE TAT:%f\n",avgtat);
    

    return 0;
}
