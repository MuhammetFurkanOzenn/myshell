#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

#define clear() printf("\033[H\033[J")

int main (int argc, char argv[], char * envp){ //, 
	
	struct dirent *d;
	const char * dir = ".";
	DIR *dh = opendir(dir);
	
	int i = 0;
	int loop = 1; 
	int id;
        int frk;
        int _wait,status;
        int exv;
	
	char _exit[]={'e','x','i','t','\0'};
	char _bash[]={'b','a','s','h','\0'};
	char _tekrar[]={'t','e','k','r','a','r','\0'};
	char _clear[]={'c','l','e','a','r','\0'};
	char _ls[]={'l','s','\0'};
	char _cat[]={'c','a','t','\0'};
    	char _islem[]={'i','s','l','e','m','\0'};
    	char _yardim[]={'!','y','a','r','d','i','m','\0'};
    	
    	char command[40];
	char * split;
    	char * word;
    	char * command_p1;
    	char * command_p2;
    	char * command_p3;
    	char * command_p4;
        
	while (loop == 1){
		
		command_p1 =NULL;
		command_p2 =NULL;
		command_p3 =NULL;
		command_p4 =NULL;
		
		printf("myshell>> ");
		scanf("%s",command); // 29[^\n]		
        	
		// word 1
	    	split=strtok(command,",");
		command_p1 = split;
		
		// word 2
	    	word=split;
	    	split=strtok(NULL,",");
	    	command_p2 = split;
	    		
	    	// word 3	
	    	word=split;
	    	split=strtok(NULL,",");
		command_p3 = split;
		
		// word 4	
	    	word=split;
	    	split=strtok(NULL,",");
		command_p4 = split;		
			
		if(strcmp(command_p1, _bash) == 0 && command_p2 == NULL){
			
			char *newargv[1];
		    	newargv[0] = "bash";
		    	
			int frk;
			int status;	
			frk = fork();
			if (frk == 0){
				status = execve("/bin/bash", newargv,NULL);
				perror("exec2: execve failed\n");
			}
			else{	
				wait(&status);
			}	
		}
		
		else if(strcmp(command_p1, _tekrar) == 0  ){	
			
		      char *newargv[2];
		      int i;

		      newargv[0] = command_p2;
		      newargv[1] = command_p3;
		      newargv[2] = NULL;

		      int f;
		      f= fork();
		      if(f==0){
			  i = execve("tekrar", newargv, envp);
			  perror("exec2: execve failed\n");

		      }else{
			  wait(&i); // forku bekle

		      }
		}
		
		else if(strcmp(command_p1, _islem) == 0  ){	
			
		      char *newargv[3];
		      int i;

		      newargv[0] = command_p2; //topla /cikar
		      newargv[1] = command_p3; 
		      newargv[2] = command_p4;
		      newargv[3] = NULL;
		      
		      int f;
		      f= fork();
		      if(f==0){
			  i = execve("islem", newargv, envp);
			  perror("exec2: execve failed\n");

		      }else{
			  wait(&i); // forku bekle
		      }
		}
		
		else if(strcmp(command_p1, _yardim) == 0 && command_p2 == NULL){
			printf("Shell'de calisan komutlar asagidadir...\n");
			printf("!yardim\n");
			printf("clear\n");
			printf("ls\n");
			printf("cat,[filename]\n");
			printf("bash\n");
			printf("tekrar,[char*],[int]\n");
			printf("islem,[topla/cikar],[int],[int]\n");
			printf("exit\n");
			
		}
		
		else if(strcmp(command_p1, _clear) == 0 && command_p2 == NULL){
			clear();
		}
		
		else if(strcmp(command_p1, _ls) == 0 && command_p2 == NULL){		
			while ((d = readdir(dh)) != NULL)
			{
				if ( d->d_name[0] == '.')
					continue;
				printf("%s  ", d->d_name);
				
			}
			printf("\n");	
		}
		
		else if(strcmp(command_p1, _cat) == 0 && command_p3 == NULL){
			FILE *file;
			char ch;
			
		       // remember file should exist
		       file = fopen(command_p2,"r");
		       
		       // reading file line by line entering to buffer line
		       while((ch= fgetc(file)) !=EOF)
		       {
		              printf("%c", ch);
		       }
		       fclose(file);	// file close
		}
			
		else if (strcmp(command_p1, _exit) == 0){
			break;
		}
		else
			printf("Yanlis bir komut girdiniz...\nKomut listesi icin /help yazabilirsiniz...\n");
		
		//fflush(stdout);
		//fflush(stdin);
		
	}
	
   return 0;
}
