// PROGRAMA p7.c
#include ...
int main(int argc, char *argv[])                                                                                                                                              Jorge Silva
{
    char prog[20];
    sprintf(prog,"%s.c",argv[1]);
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);
    printf(...);
    exit(...);
} 