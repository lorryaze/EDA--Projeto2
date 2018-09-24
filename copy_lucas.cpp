#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * randomizar(int );

int main (int argc, char *argv[]){
	int i = 0;
	int n = 50;
	int *array;
	char* sarray = (char *)calloc(n,sizeof(char));
	char *treina_asfalto[50];
	char strcaminho_asfalto[50];
	
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

			char part1[] = "DataSet\\asphalt\\asphalt_";
			char part2[] = ".txt\0";
			//concatenando strings 
			strcpy(strcaminho_asfalto, part1); //função de copia
			strcat(strcaminho_asfalto, numero); //concatenação
			strcat(strcaminho_asfalto, part2); //concatenação
			//puts(strcaminho_asfalto);
			treina_asfalto[0]=strcaminho_asfalto;
		
			puts(*(treina_asfalto+0));

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

