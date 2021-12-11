#include <stdio.h>

int main () {	
	printf("hello world!\n");
	int i = 0;
	int loop = 1; 
	char * command;
	
	while (loop == 1){
		i++;
		printf("myshell>> ");
		scanf("%s",command);
		printf("%s \n",command);
		if (i == 10){
			break;
		}
		
	}	
	
   return 0;
}
