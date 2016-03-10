// PROGRAMA p2.c
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void) {
    write(STDOUT_FILENO,"1",1);
    if(fork() > 0) {
        write(STDOUT_FILENO,"2",1);
        write(STDOUT_FILENO,"3",1);
    } else {
        write(STDOUT_FILENO,"4",1);
        write(STDOUT_FILENO,"5",1);
    }
    write(STDOUT_FILENO,"\n",1);
    return 0;
} 
*/

// p2 d)

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void) {
    printf("1\n");
    if(fork() > 0) {
        printf("2\n");
        printf("3\n");
    } else {
        printf("4\n");
        printf("5\n");
    }
    write(STDOUT_FILENO,"\n",1);
    return 0;
} 