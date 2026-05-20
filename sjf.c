#include<stdio.h>
struct process{
    int pid,bt,ct ,tat,wt;
}p[50],temp;
int main(){
    int n,i,j;
    printf("enter the number of process");
    scanf("%d",&n);
    printf("enter the burst time:");
    for(i=0;i<n;i++){
         p[i].pid=i;   
        scanf("%d",&p[i].bt);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                temp=p[j];    
                p[j]=p[j+1];
                p[j+1]=temp;
            }   
        }
    }
    p[0].ct=p[0].bt;
    p[0].tat=p[0].ct;
    p[0].wt=0;
    for(i=1;i<n;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tat=p[i].ct;
        p[i].wt=p[i].tat-p[i].bt;
    }
    for(i=0;i<n;i++){
        printf("p->%d",p[i].pid);
    }
        printf("\n\nPID\tBT\tTAT\tWT\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].bt,
               p[i].tat, p[i].wt);
    }
    float avg_tat=0 ,avg_wt=0;
    for(i=0;i<n;i++){
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    printf("avg tat= %f",avg_tat/n);
    printf("avg wt=%f",avg_wt);
