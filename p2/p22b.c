#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h> 

#define BUFFER_SIZE 512

int main(int argc, char *argv[]){
    
    int file1, file2, nr, nw;  
    unsigned char buffer[BUFFER_SIZE]; 
    
    if(argc != 3){
        printf("invalid number of arguments, insert 2 directories.\n");
        return 1;
    } 
    
    file1 = open(argv[1], O_RDONLY);
    if(file1==-1){
        perror (argv[1]);
        return 2;
    }
    
    file2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
    if(file2 == -1){
        perror(argv[2]);
        close(file1);
        return 3;
    }
    
    while((nr = read(file1, buffer, BUFFER_SIZE)) > 0){
        if((nw = write(file2, buffer, nr)) <= 0 || nw != nr){
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

