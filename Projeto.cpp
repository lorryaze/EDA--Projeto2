#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMBER_DIRECTIONS 9
#define MAX_ELEMENT 256

int GLCM [NUMBER_DIRECTIONS][MAX_ELEMENT][MAX_ELEMENT];

int * randomizar(int );
char* concat( char *, char *, char *);
void contador(char *, int *, int *);
int *matrizAlocacada(char *, int , int );
void calculaIlbp(int *, int , int ,int *);
void organizaOrdem(int *,int *, int );
void vetorDeFrequenciaIlbm(int *, int , int , int *);
int isInside(int , int , int , int );
int calculaIndice(int , int , int );
int incrementaGlcm(int *, int , int , int , int );
int calculaMax(int *, int , int );
void calculaGlcm(int *, int , int );
 double calculoContraste(int , int );
 double calculoEnergia(int , int );
 double calculoHomogenidade(int , int );
void metricasGLCM( double * ,int );
void printMatriz(int , int );

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
	int * arrayDeFequencia = (int *) calloc (512, sizeof (int)); //array de frequencia do ilbp, pode ser usado direto
	//ta sendo passado nas funções por referência.
	 double *metricaGLCM = ( double *) calloc(24, sizeof( double));


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
	printf("%s\n", treina_asfalto[0]);

	if (file == NULL){
		printf("arquivo nao encontrado");
		exit(0);
	}
	else{
		printf("O arquivo foi aberto.\n");
		contador(*treina_asfalto, &linhas, &colunas);
		fclose(file);
		matriz = matrizAlocacada(*treina_asfalto, linhas, colunas);
	}

    puts("\n");
	printf("Número de linhas do arquivo: %d\n", linhas);
	printf("Número de colunas do arquivo: %d\n", colunas);
	puts("\n");

	calculaIlbp(matriz, linhas, colunas, arrayDeFequencia);
	calculaGlcm(matriz, linhas, colunas);
	int maior = calculaMax(matriz,linhas,colunas);
	printf("%d\n", maior);


	metricasGLCM(metricaGLCM, maior);

    printf("\n");
    printf("Nome do arquivo aberto: ");
	puts(*treina_asfalto);
	free(array);
	free(arrayDeFequencia);
	free(metricaGLCM);
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
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + strlen(s3) +  1);
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);

    return result;
}

void contador(char *caminho, int *linhas, int *colunas){
    char y;
  	FILE *file;
    file = fopen(caminho,"r");

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
	fclose(file);
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

void calculaIlbp(int *matriz, int linhas, int colunas, int *arrayDeFequencia)  {
    int x = 3, y = 3, avg = 0, pos =0;
     int matrizPixels[3][3];
     unsigned int matrizBinario[3][3], matrizEspiral[3][3];
	int * arrayDeValores = (int *) calloc ((linhas-2)*(colunas-2)/9, sizeof (int));

	for (int z = 0; z < (linhas/3); z++ ){
		for(int w = 0; w < (colunas/3); w++){
			avg = 0;
			for(int i = 0; i < x; i++) {
				for(int j = 0; j < y; j++) {
					matrizPixels[i][j] = matriz[((i+(z*3))*linhas)+(j+(w*3))];
					avg += matrizPixels[i][j];
			}
		}

		avg = avg/9;

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

        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){

                matrizEspiral[i][j] = matrizBinario[i][j];

                if(i == 1 && j == 0){
                    matrizEspiral[i][j] = matrizBinario[i][j+2];
                }
                if(i == 1 && j == 1){
                    matrizEspiral[i][j] = matrizBinario[i+1][j+1];
                }
                if(i == 1 && j == 2){
                    matrizEspiral[i][j] = matrizBinario[i+1][j-1];
                }
                if(i == 2 && j == 0){
                    matrizEspiral[i][j] = matrizBinario[i][j];
                }
                if(i == 2 && j == 1){
                    matrizEspiral[i][j] = matrizBinario[i-1][j-1];
                }
                if(i == 2 && j == 2){
                    matrizEspiral[i][j] = matrizBinario[i-1][j-1];
                }
								if(i == 2 && j == 2){
                    matrizEspiral[i][j] = matrizBinario[i-1][j-1];
                }

            }
        }


		int bin[x*y];
        int indice = 0;

        for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
		 	    bin[indice] = matrizEspiral[i][j];
                indice++;
            }
		}

		int menorSomaAtual = 0, dec = 0;
        int i = 0, s = (x*y), num = (x*y);

        //Este trecho do código converte binario pra decimal.
        while( s-- ) {
            menorSomaAtual = menorSomaAtual + pow(2, i++) * (bin[s] - 0);
        };


		int ordem[x*y], m =(x*y)-1;


		for(int i = 0; i < 8; i++) {
			organizaOrdem(ordem,bin,num);
			int z =0;

			while( num-- ) {
           		dec = dec + pow(2, z++) * (ordem[num] - 0);
			}

			if (dec<menorSomaAtual){
					menorSomaAtual = dec;
				}

			num = (x*y);
		}

		arrayDeValores[pos] = menorSomaAtual;
		pos++;
		}
	}
	vetorDeFrequenciaIlbm(arrayDeValores, linhas, colunas,arrayDeFequencia);
}


void organizaOrdem(int *ordem,int *bin, int num){
	for(int i = 0; i<num; i++){
		if (i == 0){
			ordem[i]=bin[8];
		}
		else{
			ordem[i]=bin[i-1];
		}
	}
	for(int i = 0; i<num; i++){
		bin[i]=ordem[i];
	}
}

void vetorDeFrequenciaIlbm(int *array, int linhas, int colunas, int *arrayDeFequencia){
	int b=0;
	for (int i = 0; i <((linhas-2)*(colunas-2))/9; i++){
		arrayDeFequencia[array[i]]++;
	}
}
int isInside(int i, int j, int linhas, int colunas){

	if(i >= 0 && i < linhas && j >= 0 && j < colunas){
		return 1;
	}
	else{
		return 0;
	}
}
int calculaIndice(int i, int j, int colunas){
	int indice = (i*colunas+j);
	return indice;
}
int incrementaGlcm(int *matriz, int i, int j, int linhas, int colunas){
	int indice_x = calculaIndice(i, j, colunas);
	int x = matriz[indice_x]; //elemento sendo analizado

	//esse for acha o y
	for(int a = -1; a <= 1; a++){
		for(int b = -1; b <= 1; b++){
			if(a == 0 && b == 0)
				continue;

			int i_y = i+a;
			int j_y = j+b;

			int n = isInside(i_y, j_y, linhas, colunas);
			if(n == 0)
				continue;
			int m = calculaIndice(i_y, j_y, colunas);
			int y = matriz[m]; // y é a minha vizinhaça
			int p = calculaIndice(a+1, b+1, 3);

			GLCM[p][x][y]++;
		}
	}
}
int calculaMax(int *matriz, int linhas, int colunas){

	int maior = 0;
	int tamanho = linhas*colunas;

	for(int i=0;i < tamanho; i++){

		if(matriz[i] > maior){
			maior = matriz[i];
		}
	}
	return maior;

}
void calculaGlcm(int *matriz, int linhas, int colunas){

	int maior = calculaMax(matriz, linhas, colunas);

	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			incrementaGlcm(matriz, i, j, linhas, colunas);
		}
	}
}

 double calculoContraste(int p, int dim){
	double contraste=0;
	for(int i = 1; i <= dim; i++){
		for(int j = 1; j <= dim; j++){
			contraste += (pow((i-j),2)* GLCM[p][i][j]);
		}
	}
	printf("contrastes : %lf\n", contraste);
	return contraste;
}


double calculoEnergia(int p, int dim){
	double energia=0;
	for(int i = 1; i <= dim; i++){
		for(int j = 1; j <= dim; j++){
			energia +=  pow(GLCM[p][i][j],2);
		}
	}
	printf("energias : %lf\n", energia);
	return energia;
}

double calculoHomogenidade(int p, int dim){
	double homogenidade=0;

	for(int i = 1; i <= dim; i++){
		for(int j = 1; j <= dim; j++){
			homogenidade += (GLCM[p][i][j]/(1+abs(i-j)));
		}
	}
	printf("homogenidades : %lf\n", homogenidade);
	return homogenidade;
}


void metricasGLCM(double * metricaGLCM,int maior){

	for (int i = 0; i < 24; i++){
		if (i<8){
			metricaGLCM[i]= calculoContraste(i,maior);
		}
		if(i >= 8 && i < 16){
			metricaGLCM[i]= calculoEnergia(i-8, maior);
		}
		if(i>=16 && i<24){
			metricaGLCM[i]= calculoHomogenidade(i-16, maior);
		}

	}

}

void printMatriz(int p, int dim){

    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            printf(" %d", GLCM[p][i][j]);
        }
        printf("\n");
    }
}
