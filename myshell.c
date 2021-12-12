#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {	//(int argc, char *argv[]){
	
	int i = 0;
	int loop = 1; 
	int id;
        int frk;
	
	char command[40];
	char _exit[]={'e','x','i','t','\0'};
	char _bash[]={'b','a','s','h','\0'};
	char _tekrar[]={'t','e','k','r','a','r','\0'};
	
	
    	char * split;
    	char * word;
    	char * command_p1;
    	char * command_p2;
    	char * command_p3;
    	char * command_p4;

	//printf("%s %s\n",_exit, _bash);
        
	//while (loop == 1){
		
		printf("myshell>> ");
		scanf("%29[^\n]",command);
		fflush(stdin);
		fflush(stdout);
        	printf("command :: %s\n" , command);
		
		// word 1
	    	split=strtok(command," ");
		command_p1 = split;
		printf("pp : %s \n", command_p1);
		
		// word 2
	    	word=split;
	    	split=strtok(NULL," ");
	    	command_p2 = split;
		printf("pp : %s \n", command_p2);
	    		
	    	// word 3	
	    	word=split;
	    	split=strtok(NULL," ");
		command_p3 = split;
		printf("pp : %s \n", command_p3);
		
		// word 4	
	    	word=split;
	    	split=strtok(NULL," ");
		command_p4 = split;
		printf("pp : %s \n", command_p4);
		
		if (command_p4 == NULL)
			printf(" p4 is NULL\n");
			
		if(strcmp(command_p1, _bash) == 0 && command_p2 == NULL){
			printf("Bash'a geciliyor...\n");
				
			/*frk = fork();
			if (frk == 0){
				printf("child pid : %d\n",getppid());
				sleep(5);
				printf("child pid after sleep: %d\n",getppid());	
			}
			else{
				printf("ppid : %d\n",getpid());
			}*/	
		}
		
		else if(strcmp(command_p1, _tekrar) == 0){
			
			printf("Tekrar'a geciliyor...\n");
		}
			
		else if (strcmp(command_p1, _exit) == 0){
			//break;
		}
		else
			printf("Yanlis bir komut girdiniz...\nKomut listesi icin /help yazabilirsiniz...\n");
		
	//}
	
		
   return 0;
}
