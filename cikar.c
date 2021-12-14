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

int main (int argc, char *argv[]){   
	
	int firstVal= strtoint(argv[1]);
	int secondVal= strtoint(argv[2]);
	
	int pipefd[2];
	int firstValP,secondValP,result;
	
	if(firstVal == -1 || secondVal == -1)
		printf("Yanlis bir deger girdiniz...\nOrnek komut: islem,topla,2,2\n");
	else{
		printf("%d - %d = %d\n",firstVal, secondVal, (firstVal-secondVal));
		
		
		//
		
		read(3, &firstValP, sizeof(result));
		printf("firstValP :: %d\n",firstValP );
		read(3, &secondValP, sizeof(result));
		printf("secondValP :: %d\n",secondValP );
		result = firstValP - secondValP;
		
		write(4,&result,sizeof(result));
	}
}
