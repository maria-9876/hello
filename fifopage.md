#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,RQ[20],initial,i;
    printf("Enter the no of requests:");
    scanf("%d",&n);
    printf("Enter the request sequence:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }
    printf("enter the initial head position:");
    scanf("%d",&initial);
    int Totalseektime=0;
     for(i=0;i<n;i++)
    {
        Totalseektime=Totalseektime+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("Totalseektime using FCFS is: %d",Totalseektime);
}
