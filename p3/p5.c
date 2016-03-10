#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX 50000

int main(void) {
    pid_t pid;
    pid_t pid2;
    
    pid=fork();
    switch (pid) {
            case -1:
                perror("fork");
                break;
            case 0: //filho
                 write(STDOUT_FILENO,"Hello ",6);
                 break;
            default: //pai
            wait(NULL);
            pid2=fork();
            switch(pid2){
                case -1:
                    perror("fork");
                    break;
                case 0: //filho
                    write(STDOUT_FILENO,"my ",3);
                    break;
                default: //pai
                    wait(NULL);
                    write(STDOUT_FILENO,"friends!\n",9);
            }        
    }
    //write(STDOUT_FILENO,"\n",1);
    return 0;
} 
