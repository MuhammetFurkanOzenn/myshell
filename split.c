#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    char inputt [40];
    scanf("%29[^\n]",inputt);
    char * input; 
    input = inputt;
    printf("input :: %s\n" , input);
    
    char * split;
    char * word;
    char * p1;
    char * p2;
    char * p3;
    char * p4;
    
    
    	// word 1
    	split=strtok(input," ");
	p1 = split;
	printf("pp : %s \n", p1);
	
	// word 2
    	word=split;
    	split=strtok(NULL," ");
    	p2 = split;
	printf("pp : %s \n", p2);
    		
    	// word 3	
    	word=split;
    	split=strtok(NULL," ");
	p3 = split;
	printf("pp : %s \n", p3);
	
	// word 4	
    	word=split;
    	split=strtok(NULL," ");
	p4 = split;
	printf("pp : %s \n", p4);
	
	if (p4 == NULL)
		printf(" p4 is NULL\n");
    
    return 0;
}
