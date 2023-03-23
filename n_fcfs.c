#include<stdio.h>

   int pro[100][4];
 void readProcess(int n){
    for (int i = 0 ; i < n ; i++){
     
        printf("Enter process arrival time : ");
        
        scanf("%d", &pro[i][0]);
        printf("Enter process burst time : ");
        
        scanf("%d", &pro[i][1]);
       
    }
     }
    
 
 
 
void display(int n ){
 
 printf(" process no \t      Arrival Time \t     Burst Time\t     Waiting Time\t     Turn around Time \n");
 
 for (int i = 0 ; i < n ;i++ ){
      printf("  %d   \t\t\t ", i) ;
      printf("  %d   \t\t\t ", pro[i][0]);
      printf("  %d   \t\t ", pro[i][1]);
      printf("  %d   \t\t ", pro[i][2]);
      printf("  %d   \n", pro[i][3]);

 }
 
 }
 
 
 int avgwt = 0;
 int avgt =0;
 
 
 void calculate(int n){
 
    int cprocess = 0;
   for (int i =0 ;cprocess < n; 0 ){
     if (pro[cprocess][0] <= i ) {
           if (pro[cprocess][0] < i )
            {pro[cprocess][2] = i - pro[cprocess][0] ;} 
            else {pro[cprocess][2] = 0;}
        pro[cprocess][3] = pro[cprocess][2] + pro[cprocess][1];
        avgwt = avgwt + pro[cprocess][2];
        avgt = pro[cprocess][3];
        i = i + pro[cprocess][1];
        cprocess++;
     }else {
            
   i++;
     }

   }
 }
 
 
void main(){
     int n = 0;
    printf("enter number of processs");
    scanf("%d", &n);
    
    readProcess(n);
    calculate(n);
    display(n);
    
    printf("Average Waiting Time : %d \n\n",(avgwt/n));
  
  
  
  
 
}

