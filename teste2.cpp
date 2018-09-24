#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * randomizar(int );
char * treinamento_asfalto(int , int *);

int main (int argc, char *argv[]){
	int i = 0;
	int n = 50;
	int *array;
	char *treino_asfalto[n];
	char* sarray = (char *)calloc(n,sizeof(char));
	
	array = randomizar(n);
	
	for(i=0; i<50; i++){
		sarray[i] = *(array+i);
		//printf("%d\n", *(sarray+i));
	}
	treino_asfalto = treinamento_asfalto(n, array);
	
	free(array);
	free(sarray);
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

char * treinamento_asfalto(int n, int *array){
	int i = 0;
	char strcaminho_asfalto[50];
	char * treina_asfalto = (char *) calloc (n, sizeof (char));
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
			treina_asfalto[i]=strcaminho_asfalto;
		
			puts(*(treina_asfalto+i));

		}
     
    return treina_asfalto;
}


/*
char * concatenacao(char parray[2]){
	char* strcaminho_asfalto = (char *)calloc(1,sizeof(char));
	char part1[] = "DataSet\\asphalt\\asphalt_0";
	char part2[2] = parray[2];
	char part3[] = ".txt";
	strcpy(strcaminho_asfalto, part1); //função de copia
	strcat(strcaminho_asfalto, part2); //concatenação
	strcat(strcaminho_asfalto, part3); //concatenação
	
	return strcaminho_asfalto;
	 
}*/


