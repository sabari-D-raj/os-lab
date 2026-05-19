#include<stdio.h>
#include<stdlib.h>
struct sjf{
    int pid,bt,wt,tat;
}p[10]; 
int main(){
    int twt=0,tott=0;
    struct sjf temp;
    int n,i;
    printf("enter the number process:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i].pid=i;
        printf("enter the burst time:");
        scanf("%d",&p[i].bt);
    }
    for(i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

        }
    }
    p[0].wt=0;
    p[0].tat=p[0].bt;
    for(i=1;i<n;i++){
        p[i].wt=p[i-1].wt+p[i].bt;
        p[i].tat=p[i].wt+p[i].bt;
    }
    for(i=0;i<n;i++){
        twt+=p[i].wt;
        tott+=p[i].tat;
    }
    printf("total wt: %d \n" ,twt);
    printf("average wt: %d\n" ,twt/n);
    printf("total tat: %d\n",tott);
    printf("average tat %d\n",tott/n);
    return 0;
}
