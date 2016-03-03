#include <stdio.h>
int main(int argc, char *argv[])
{
	
	int i;
	int j;
	int final=ato(argv[1]);
	for(j=0; j<final;j++){
		printf("Hello ");
		for(i=2; i<
; i++){
			
			printf("%s ", argv[i]);
		}
		printf("! \n");
	}
	return 0;
}
