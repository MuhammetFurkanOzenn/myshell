#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            break;
         }
 }
 return number;
}

int main (int argc, char *argv[],char * envp){
	
	
	char _topla[]={'t','o','p','l','a','\0'};
	char _cikar[]={'c','i','k','a','r','\0'};   
	
	int firstVal= strtoint(argv[1]);
	int secondVal= strtoint(argv[2]);
	if (strcmp(argv[0], _topla) == 0){	//topla ya da cikar
		char *newargv[3];
	        int i;

	        newargv[0] = argv[0]; //topla | cikar
	        newargv[1] = argv[1]; 
	        newargv[2] = argv[2];
	        newargv[3] = NULL;
	        
		i = execve("topla", newargv, envp);
				
	}else if (strcmp(argv[0], _cikar) == 0){
		
		char *newargv[3];
	        int i;

	        newargv[0] = argv[0]; //topla | cikar
	        newargv[1] = argv[1]; 
	        newargv[2] = argv[2];
	        newargv[3] = NULL;
	        
		i = execve("cikar", newargv, envp);
		
	}else{
		printf("Yanlis bir deger girdiniz...\nOrnek komut: islem,topla,2,2\n");
	}	
}
