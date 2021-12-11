#include <stdio.h>
#include <stdlib.h>

int main () {	//(int argc, char *argv[]){
	printf("hello world!\n");
	int i = 0;
	int loop = 1; 
	//char * command;
	char command[40];
	
	char command_p1[40]; // tekrar
	char command_p2[40]; // sultan
	char command_p3[40]; // 2
	char command_p4[40]; // null | sayi
	
	
	char _exit[]={'e','x','i','t','\0'};
	char _bash[]={'b','a','s','h','\0'};
	char _tekrar[]={'t','e','k','r','a','r','\0'};
	
        printf("%s %s\n",_exit, _bash);
        int id;
	// while 
	while (loop == 1){
		
		printf("myshell>> ");
		scanf("%s",command);
		printf("%s \n",command);
		
		if(strcmp(command, _bash) == 0){
			printf("Bash'a geciliyor...\n");
		}
		else if(strcmp(command, _tekrar) == 0){
			
			printf("Tekrar'a geciliyor...\n");
		}
			
		else if (strcmp(command, _exit) == 0){
			break;
		}
		else
			printf("Yanlis bir komut girdiniz...\nKomut listesi icin /help yazabilirsiniz...");
		
	}
	
		
   return 0;
}
