#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * randomizar(int );
char* concat( char *, char *s2, char *s3);
int *contador(FILE *file);

int main (int argc, char *argv[]){
	int n = 50;
	int *array;
	char *treina_asfalto[25];
	char *teste_asfalto[25];
	char *treina_grama[25];
	char *teste_grama[25];
	
	array = randomizar(n);

	for (int i =0; i <n; i++){
			
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
	}
	
    FILE *file;
    file = fopen(*(treina_asfalto),"r");
    int *arr;
    arr = contador(file);
  
    for(int i = 0; i < 2; i++){
        printf("%d\n", *(arr+i));
    }
   
    puts(*treina_asfalto);	
	free(array);
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

int *contador(FILE *file){
	
    int linhas, colunas;
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
    
    int arr[] = {linhas, colunas};
    int *retorno = (int *) calloc(2, sizeof(int));
    
    return retorno;  
}
