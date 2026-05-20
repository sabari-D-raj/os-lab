#include<stdio.h>
int main(){
    int n,m ,i,j,k;
    printf("enter the number of process");
    scanf("%d",&n);
    printf("enter the number of the resources:");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],need[n][m];
    int aval[m];
    printf("enter the alloaction matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter the max matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter the available resources:");
    for(i=0;i<m;i++){
        scanf("%d",&aval[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int finish[n],safeseq[n];
    for(i=0;i<n;i++){
        finish[i]=0;
    }
int count=0;

while(count<n){
    int found=0;

    for(i=0;i<n;i++){

        if(finish[i]==0){

            for(j=0;j<m;j++){
                if(need[i][j] > aval[j]){
                    break;
                }
            }

            if(j==m){

                for(k=0;k<m;k++){
                    aval[k] += alloc[i][k];
                }

                safeseq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }
    }

    if(found==0){
        printf("No safe sequence\n");
        return 0;
    }
}
    printf("safe seq");
    for(i=0;i<n;i++){
        printf(" p->%d",safeseq[i]);
    }
    return 0;
  
}
