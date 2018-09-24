#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * randomizar(int );
char* concat( char *, char *s2, char *s3);

int main (int argc, char *argv[]){
	int i = 0;
	int n = 50;
	int *array;
	char* sarray = (char *)calloc(n,sizeof(char));
	char *treina_asfalto[25];
	
	array = randomizar(n);
	
	for(i=0; i<50; i++){
		sarray[i] = *(array+i);
		//printf("%d\n", *(sarray+i));
	}
	

	for (i =0; i <(n/2); i++){
			
			char numero[] = " ";
			numero[0] = ((*(array+i))/10) + '0';
			int num = ((*(array+i))/10)*10;
			numero[1] = ((*(array+i))-num) + '0';
			printf("%d\n", *(array+i));

			char * strcaminho_asfalto = concat("DataSet\\asphalt\\asphalt_", numero, ".txt"); 

			treina_asfalto[i]=strcaminho_asfalto;
		
			puts(*(treina_asfalto+i));

	}
	
	for (i =0; i<25; i++){

		puts(*(treina_asfalto+i));

	}
	
	free(array);
	free(sarray);
//	free(treina_asfalto);
	return 0;
}

int * randomizar(int n){
	//srand(time(0)); 
	int i;
    int * array = (int *) calloc (n, sizeof (int));
    for (i = 0; i < n; ++i) {
        array[i] = i+1;
    }
 	for ( i = 0; i < n; i++) {    
    	int temp = array[i];
   		int randomIndex = rand() % n;
  		array[i]= array[randomIndex];
    	array[randomIndex] = temp;
	}
    return array;
}

char* concat( char *s1,  char *s2,  char *s3)
{
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + strlen(s3) +  1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    return result;
}
