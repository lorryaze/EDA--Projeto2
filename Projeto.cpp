#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * randomizar(int );
char* concat( char *, char *s2, char *s3);
void contador(FILE *, int *, int *);
int *matrizAlocacada(char *, int , int );
void calculaIlbp(int *matriz, int linhas, int colunas);

int main (int argc, char *argv[]){
	int n = 50;
	int *array;
	char *treina_asfalto[25];
	char *teste_asfalto[25];
	char *treina_grama[25];
	char *teste_grama[25];
	int *matriz;
	int linhas = 0, colunas = 1;

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

	if (file == NULL){
		printf("arquivo nao encontrado");
		exit(0);
	}
	else{
		printf("O arquivo foi aberto.\n");
		contador(file, &linhas, &colunas);
		fclose(file);
		matriz = matrizAlocacada(*treina_asfalto, linhas, colunas);
	}

    puts("\n");
	printf("Número de linhas do arquivo: %d\n", linhas);
	printf("Número de colunas do arquivo: %d\n", colunas);
	puts("\n");

	calculaIlbp(matriz, linhas, colunas);
    printf("\n");
    printf("Nome do arquivo aberto: ");
	puts(*treina_asfalto);
	free(array);
	return 0;
}

int * randomizar(int n){

   // srand(time(0));
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

void contador(FILE *file, int *linhas, int *colunas){
    char y;


	while(fscanf(file,"%c",&y) != EOF)
	{
		if(*linhas == 0){
			if(y == ';'){
			*colunas += 1;
			}
		}
		if(y == '\n')
			*linhas += 1;
	}
}

int *matrizAlocacada(char *caminho, int linhas, int colunas){
	int n;
	n = linhas*colunas;
	int x=0;
	char y=0;
	int *matriz = (int *) calloc (n, sizeof(int));
	FILE *file;
	file = fopen(caminho,"r");
	if (file == NULL){
		printf("arquivo nao encontrado");
		exit(0);
	}
	else{
		for(int i=0;i <linhas; i++){
			for(int j=0; j<colunas; j++){
				fscanf(file,"%d%c",&x,&y);
				matriz[i*linhas+j] = x;
			}
		}
	}
	fclose(file);
	return matriz;
}

void calculaIlbp(int *matriz, int linhas, int colunas) {
    int x, y;
    x = y = 3;
    long int matrizPixels[3][3];
    long unsigned int matrizBinario[3][3];
    long unsigned int matrizEspiral[3][3];
    //int *vetorMin[];

    int avg = 0;

		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				matrizPixels[i][j] = matriz[i*linhas*j];
				avg += matrizPixels[i][j];
			}
		}

		avg = avg/9;
		printf("AVG: %d\n", avg);

		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++) {
				if((matrizPixels[i][j] - avg) >= 0) {
					matrizBinario[i][j] = 1;
				}
				else {
					matrizBinario[i][j] = 0;
				}
			}
		}

        puts("Matriz Binario:");
		 for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
		 		printf("%lu", matrizBinario[i][j]);
		 	}
		 }
        puts("\n");

        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {

                matrizEspiral[i][j] = matrizBinario[i][j];

                if(i == 1 && j == 0) {
                    matrizEspiral[i][j] = matrizBinario[i][j+1];
                }
                if(i == 1 && j == 1) {
                    matrizEspiral[i][j] = matrizBinario[i+1][j+1];
                }
                if(i == 1 && j == 2) {
                    matrizEspiral[i][j] = matrizBinario[i+1][j-1];
                }
                if(i == 2 && j == 0) {
                    matrizEspiral[i][j] = matrizBinario[i][j];
                }
								if(i == 2 && j == 1) {
                    matrizEspiral[i][j] = matrizBinario[i-1][j-1];
                }
								if(i == 2 && j == 2){
                    matrizEspiral[i][j] = matrizBinario[i-1][j-1];
                }

            }
        }

        puts("Matriz Espiral:");

        for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
		 		printf("%lu", matrizEspiral[i][j]);
		 	}
		}
        puts("\n");

        int bin[x*y];
        int indice = 0;

        for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
		 	    bin[indice] = matrizEspiral[i][j];
                indice++;
            }
		}

        puts("bin");
        for(int i = 0; i < indice; i++){
            printf("%d", bin[i]);
        }
        puts("\n");

        unsigned long dec = 0;
        int i = 0;
        int s = x*y;

        //Este trecho do código converte binario pra decimal.


        while( s-- ) {
            dec = dec + pow(2, i++) * (bin[s] - 0);
        };

        printf("\nDecimal Equivalent of Binary Number: %lu\n", dec);




        // for(int j = 2; j >= 0; j--) {
    //     for(int i = 0; i < 3; i++) {
    //            printf("%d      ", matrizIlbp[i][j]);
    //     }
    //     printf("%c", 10);
		// }
}
