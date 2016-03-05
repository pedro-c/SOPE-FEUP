#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define BUFFER_SIZE 512
int main(int argc, char *argv[])
{
   unsigned char buffer[BUFFER_SIZE]; 
   int file1, nr, nw;
   
   if(argc != 2){
       printf("Invalid number of arguments.\n");
       return 1;
   }
   
   int n=0;
   write(STDOUT_FILENO, "How many students will you add? ", 32);
   read(STDIN_FILENO, buffer, BUFFER_SIZE);
   n=atoi(buffer);
   
   file1 = open(argv[1],  O_WRONLY | O_CREAT | O_EXCL, 0644);
    if(file1 == -1){
        perror(argv[1]);
        close(file1);
        return 2;
    }
    
    dup2(file1,STDOUT_FILENO);
   
   int i=0;
   for(i; i<n; i++){
       
       printf("Name:");
        write(STDOUT_FILENO, "Name:", 5);
        nr=read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr){
            close(file1);
            return 3;
        }
        
        printf("Score:");
        write(STDOUT_FILENO, "Score:", 6);
        nr=read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr){
            close(file1);
            return 4;
        }
        
             
   }
  
   return 0;
} 
