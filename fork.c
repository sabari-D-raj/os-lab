#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("error");
        return 1;
    }
    else if(pid==0){
        printf("pccst402");
   }
   else{
        wait(NULL);
        printf("os");
   }
   return 0;
}


