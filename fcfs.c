#include<stdio.h>
struct process{
    int pid ,bt,ct,tat,wt;
}p[20];
int main(){
    int n,i;
    printf("enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i;
        printf("enter the burst  time:");
        scanf("%d",&p[i].bt);
    }
    p[0].ct=p[0].bt;
    p[0].tat=p[0].ct;
    p[0].wt=0;
    for(i=1;i<n;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tat=p[i].ct;
        p[i].wt=p[i].tat-p[i].bt;
    }
       printf("process order \n");
    for(i=0;i<n;i++){
        printf("p->%d",p[i].pid);
    }
    printf("\n pid \t bid \t turn aroundtime \t waiting time \n");
    for(i=0;i<n;i++){
        printf("%d \t %d\t%d\t%d\t \n",p[i].pid,p[i].bt,p[i].tat,p[i].wt);
    }
    int avg_tat=0;
    int avg_wt=0;
    for(i=0;i<n;i++){
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    printf("average tat %d\n ",avg_tat/n);
    printf("average wt %d",avg_wt/n);
    return 0;
}
