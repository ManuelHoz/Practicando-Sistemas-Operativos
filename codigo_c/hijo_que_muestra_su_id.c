#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int status; //almacena estado de proceso hijo
    int pid= fork();   
    if (pid<0){
        printf("ERROR");
    }
    else if (pid==0){
        printf("mi pid es:%d", getpid());
        printf("\n");
        printf("mi padre es:%d", getppid());
        printf("\n");
        exit(0);
    }
    else if(pid>0){
        wait(&status);
        printf("soy el padre %d", pid);
        printf("\n");
        return 0;
    }
}