#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,totalT=0,pos,temp;
    float avgwt,avgtat;
    printf("Enter the number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;          
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    
    avgwt=(float)total/n;
    printf("\nProcess\t Priority\tBurst time   \tWaiting time\tTurnaround time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        totalT+=tat[i];
        printf("\nP[%d]\t %d\t     \t%d\t\t    %d\t\t\t%d",p[i],pr[i],bt[i],wt[i],tat[i]);
    }
 
    avgtat=(float)totalT/n;
    printf("\nAverage waiting time=%f",avgwt);
    printf("\nAverage turnaround time=%f\n",avgtat);
 
return 0;
}
