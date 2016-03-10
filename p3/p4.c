#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX 50000

//a)
/*
int main(void) {
    pid_t pid;

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
                 write(STDOUT_FILENO,"World !\n",8);
                 
    }
    //write(STDOUT_FILENO,"\n",1);
    return 0;
} 
*/
//b)

int main(void) {
    pid_t pid;

    pid=fork();
    
    switch (pid) {
            case -1:
                perror("fork");
                break;
            case 0: //filho
                write(STDOUT_FILENO,"World !\n",8);
                break;
            default: //pai
                 //wait(NULL);
                 write(STDOUT_FILENO,"Hello ",6);
                
                 
    }
    //write(STDOUT_FILENO,"\n",1);
    return 0;
}