#include <stdio.h>


struct process 

{
    int id, at, bt, ct, wt, tat;
};


struct process p[100];


struct process temp;



int main() 

{
    int n, i, j, k, min, ct = 0, evaluated = 0, completed = 0, tq, rem[100];
    

printf("Enter the no of process: ");
    

scanf("%d", &n);
    

printf("Enter the id, at and bt:\n");
    

for (i = 0; i < n; i++) {
        

scanf("%d %d %d", &p[i].id, &p[i].at, &p[i].bt);
        

rem[i] = p[i].bt;
    }
    

printf("Enter the time quantum: ");
    

scanf("%d", &tq);

    

while (completed < n) {
        

evaluated = 0;
        

for (i = 0; i < n; i++) {
            

if (p[i].at <= ct && rem[i] > 0) {
                

evaluated = 1;
               

 if (rem[i] <= tq) {
                   

 ct += rem[i];
                    

completed++;
                    

rem[i] = 0;
                    

p[i].ct = ct;
                   

 p[i].tat = p[i].ct - p[i].at;
                    

p[i].wt = p[i].tat - p[i].bt;
               

 } 

else {
                    

rem[i] -= tq;
                    

ct += tq;
                }
            }
        }
        

if (evaluated == 0) 

{
            ct++;
        }
    }

    

// Arranging the process according to the ID
    

for (j = 1; j < n; j++) {
        

for (i = 0; i < n - j; i++) {
            

if (p[i].id > p[i + 1].id) {
                

temp = p[i];
                

p[i] = p[i + 1];
                

p[i + 1] = temp;
            }
        }
    }

    

printf("\n----ROUND ROBIN----\n");
    

printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    

for (i = 0; i < n; i++) {
        

printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    

return 0;
}
