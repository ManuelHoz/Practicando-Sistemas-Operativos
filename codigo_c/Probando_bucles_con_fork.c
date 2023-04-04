#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int cantidad_de_hijos=0;
int i=0;
int cantidad_de_fork;

int main(){
    int pid;
    cantidad_de_fork=0;
    int status;
    for (i=0; i<2; i++){
        pid=fork();
        printf("fork actual numero:%d   proceso:%d\n", cantidad_de_fork, getpid());
        cantidad_de_fork++;
        printf("yo soy :%d, mi padre es: %d", getpid(), getppid());
        printf("\n");
    }
    if(pid==0){
        printf("yo muero aqui:%d\n", getpid());
        exit(0);
    }
    else if(pid>0){
        while (cantidad_de_hijos!=i)
        {
            wait(&status);
            cantidad_de_hijos++;
        }
        printf("yo, el padre, muero aqui, soy: %d\n",getpid());
        return 0;
    }
}
