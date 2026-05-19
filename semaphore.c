#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
void producer(){
    --mutex;
    --empty;
    printf("producer produces item");
    x++;
    ++mutex;
    ++full;
}
void consumer(){
    --mutex;
    --full;
    printf("consumer conusumes");
    x--;
    ++mutex;
    ++empty;
}
int main(){
    int n;
    do{
        printf("enter your choice:");
        scanf("%d",&n);
        switch(n){
            case 1:if(mutex==1 && empty!=0){
                producer();
            }
            else{
                printf("buffer full");
            }
            break;
            case 2:if(mutex==1 && full!=0){
                consumer();
            }
            else{
                printf("buffer empty");
            }
            break;
            case 3:break;
            
        }
    }while(n!=3);
    return 0;
}
