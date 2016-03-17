#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int inc=1;

void handler(int signo) /* argument is signal number */
{ 
    if (signo == SIGUSR1){
        inc=1;
    } 
    else if (signo == SIGUSR2){
        inc=-1;
    } 
}

int main(void)
{ 
    int v=0, count=0;
    time_t t;
    signal(SIGUSR1,handler);
    signal(SIGUSR2,handler);
    int n;
    srand((unsigned) time(&t));
       
    int pid=fork();
    if(pid>0)//pai
    {
        
       //while(waitpid(-1,NULL,WNOHANG)==0){
         while(1){  
            n=rand();
            //printf("n=%d\n", n);
            if(rand()%2 == 0){
                kill(pid,SIGUSR1);
            }
            else{
                kill(pid,SIGUSR2);
            }
            sleep(1);
        }
    }else//child
    {
        while(count!=50){
            printf("%d \n", v);
            v=v+inc;
            count++;
            sleep(1);
        }
    }
    
}
