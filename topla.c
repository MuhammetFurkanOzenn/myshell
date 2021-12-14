#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){   
	
	int result;
	int pipefd[2];
	int firstValP,secondValP;
	if(firstValP == -1 || secondValP == -1)
		printf("Yanlis bir deger girdiniz...\nOrnek komut: islem,topla,2,2\n");
	else{
		read(3, &firstValP, sizeof(result));
		read(3, &secondValP, sizeof(result));
		result = firstValP + secondValP;
		
		write(4,&result,sizeof(result));
	}	
}
