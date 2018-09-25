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
	char *treina_asfalto[50];
	char *teste_asfalto[25];
	char *treina_grama[25];
	char *teste_grama[25];
	
	array = randomizar(n);
	
	for(i=0; i<50; i++){
		sarray[i] = *(array+i);
		//printf("%d\n", *(sarray+i));
	}
	

	for (i =0; i <n; i++){
			
			char numero[] = "  ";
			numero[0] = ((*(array+i))/10) + '0';
			int num = ((*(array+i))/10)*10;
			numero[1] = ((*(array+i))-num) + '0';
			
			char part2[] = ".txt";
			char part1asf[] = "DataSet/asphalt/asphalt_";
			char part1gram[] = "DataSet/grass/grass_";
			char * strcaminho_asfalto = concat(part1asf, numero, part2); 
			char * strcaminho_grama = concat(part1gram, numero, part2);
			if (i <25){
				treina_asfalto[i]=strcaminho_asfalto;
				treina_grama[i]=strcaminho_grama;
			}
			else{
				teste_asfalto[i-25]=strcaminho_asfalto;
				teste_grama[i-25]=strcaminho_grama;
			}
		//	free(strcaminho_asfalto);
		//	free(strcaminho_grama);
	
	}

	
	for (i =0; i<25; i++){
		printf("%s\n", *(treina_asfalto+i));
	}
	printf("agr o teste:\n");
		for (i =0; i<25; i++){
		printf("%s\n", *(teste_asfalto+i));
	}
	printf("agr e grama treina:\n");
		for (i =0; i<25; i++){
		printf("%s\n", *(treina_grama+i));
	}
	printf("agr e grama teste:\n");
		for (i =0; i<25; i++){
		printf("%s\n", *(teste_grama+i));
	}
	
	FILE *file;
	char ch;
	char frase[100];
	
	file = fopen(*(treina_asfalto),"r");
	
    int x,linhas, colunas;
    char y;
    linhas = 0;
    colunas = 1;

	if (file == NULL){
		printf("arquivo não encontrado");
		exit(0);
	}
	else{
		printf("arquivo encontrado\n");
		while(fscanf(file,"%c",&y) != EOF)
        {
            if(linhas == 0){
                if(y == ';')
                    colunas ++;
            }
            if(y == '\n')
                linhas++;
        }
    }
   
    printf("Linhas: %d, Colunas: %d\n", linhas, colunas);
    puts(*treina_asfalto);	
	free(array);
	free(sarray);
//	free(treina_asfalto);
	fclose(file);
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
