#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMBER_DIRECTIONS 9
#define MAX_ELEMENT 256

int GLCM [NUMBER_DIRECTIONS][MAX_ELEMENT][MAX_ELEMENT];
int isInside(int , int , int , int );
int calculaIndice(int , int , int );
int incrementaGlcm(int *, int , int , int , int );
int calculaMax(int *, int , int );
void calculaGlcm(int *, int , int );
void printMatriz(int , int );

int main(){
    int linhas = 3;
    int colunas = 3;
    int n = linhas*colunas;

    int *matriz = (int *) calloc(n , sizeof(int));
    int arr[] = {1, 2, 3,
                1, 2, 3,
                2, 1, 2};
    
    matriz = arr;
    for(int i = 0; i < n; i++){
        printf("%d\n", matriz[i]);
    }
    calculaGlcm(matriz,linhas,colunas);
    int maior = calculaMax(matriz,linhas,colunas);
    printMatriz(0, maior);
    puts("\n");
    printMatriz(1, maior);
    puts("\n");
    printMatriz(2, maior);
    puts("\n");
    printMatriz(3, maior);
    puts("\n");
    printMatriz(4, maior);
    puts("\n");
    printMatriz(5, maior);
    puts("\n");
    printMatriz(6, maior);
    puts("\n");
    printMatriz(7, maior);
    
    return 0;
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
void printMatriz(int p, int dim){
    
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            printf(" %d", GLCM[p][i][j]);
        }
        printf("\n");
    }
}