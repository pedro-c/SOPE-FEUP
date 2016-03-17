#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_usr(int); /* one handler for both signals */

int v=0;

void sig_usr(int signo) /* argument is signal number */
{ 
    if (signo == SIGUSR1){
        v++;
        printf("%d \n", v);
        printf("Received SIGUSR1\n");    
    } 
    else if (signo == SIGUSR2){
        v--;
        printf("%d \n", v);
        printf("Received SIGUSR2\n");
    } 
}

int main(void)
{ 
    
    struct sigaction action;
    action.sa_handler = sig_usr;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(SIGUSR1,&action,NULL) < 0)
    {
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");
        exit(1);
        
     }
    if (sigaction(SIGUSR2,&action,NULL) < 0)
    {
        
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");
        exit(1);
     }
     
    //printf("Try me with CTRL-C ...\n");
    while(1) pause();
    exit(0);
}
