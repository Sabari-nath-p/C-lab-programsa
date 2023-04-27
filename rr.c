#include <stdio.h>

int i,n,t;
void read(int b[]) {
    printf("\nEnter Burst Time of each process\n");
    for (i = 0; i < n; ++i) {
        printf("Process %d : ", i);
        scanf("%d", &b[i]);
    }
}

void findWaitingtime(int b[], int wt[]) {
    int brem[20];
    for (i = 0; i < n; ++i) {
        brem[i] = b[i];                        
    }
    int time = 0;                          

    while (1)
    {

        int flag = 0;

        for (i = 0; i < n; ++i) {

            if (brem[i] > 0) {                 
                flag = 1;                       
                if (brem[i] > t) {
                    time += t;            
                    brem[i] -= t;        
                }
                else {                         
                    time += brem[i];           
                    wt[i] = time - b[i];        
                    brem[i] = 0;               
                }
            }
        }
        if (flag == 0) {                       
            break;
        }
    }
}

void findTurnAroundtime(int tat[], int b[], int wt[]) {
    for (i = 0; i < n; ++i) {
        tat[i] = b[i] + wt[i];
    }
}

void display(int b[], int wt[], int tat[]) {
    int wtSum = 0, tatSum = 0;
    printf("Process\tBurstTime WaitingTime  TurnAroundTime\n");

    for (i = 0; i < n; ++i) {
        wtSum += wt[i];
        tatSum += tat[i];
        printf("%3d\t%6d\t\t%d\t%5d\n", i, b[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %d", (int)wtSum / n);
    printf("\naverage turnaround time: %d", (int)tatSum / n);
    printf("\n");
}

void calcTime(int b[], int wt[], int tat[]) {
    findWaitingtime(b, wt);
    findTurnAroundtime(tat, b, wt);
    display(b, wt, tat);
}

void main()
{
    int b[20], tat[20], wt[20];
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    read(b);
    printf("\nEnter time quantum:");
    scanf("%d", &t);
    calcTime(b, wt, tat);
}
