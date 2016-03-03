#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h> 
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]){
    
    size_t nr, nw;  
    unsigned char buffer[BUFFER_SIZE]; 
    FILE *file1;
    FILE *file2;
    
    if(argc != 3){
        printf("invalid number of arguments, insert 2 directories.\n");
        return 1;
    } 
    
    file1 = fopen(argv[1], "r");
    if(file1==-1){
        perror (argv[1]);
        return 2;
    }
    
    file2 = fopen(argv[2], "a");
    if(file2 == -1){
        perror(argv[2]);
        close(file1);
        return 3;
    }
    
    while((nr = fread(buffer, 1, BUFFER_SIZE, file1)) > 0){
        if((nw = fwrite(buffer, 1, BUFFER_SIZE, file2)) <= 0 || nw != nr){
            perror(argv[2]);
            close(file1);
            close(file2);
            return 4;
        }
    }
    
       close(file1);
       close(file2);
       return 0;
}

