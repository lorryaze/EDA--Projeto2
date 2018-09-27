#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void calculaIlbp(int *matriz, int linhas, int colunas);

int main (int argc, char *argv[]){
	int n = 3*3;
    int matrizInicio[3][3];
    int linhas = 3, colunas = 3;
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matrizInicio[i][j] = i*6;
        }
    }
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d",  matrizInicio[i][j]);
        }
    }
    puts("\n");
    
    int *matriz = (int *) calloc(n, sizeof(int));
    matriz = matrizInicio;

    calculaIlbp(matriz, linhas, colunas);
    
	return 0;
}

/*int *matrizAlocacada(int *caminho, int linhas, int colunas){
	int n;
	n = linhas*colunas;
	int x=0;
	int *matriz = (int *) calloc (n, sizeof(int));

	for(int i=0;i <linhas; i++){
		for(int j=0; j<colunas; j++){
			scanf("%d",&x);
			matriz[i*linhas+j] = x;
		}
	}
	return matriz;
}*/
void calculaIlbp(int *matriz, int linhas, int colunas) {
	
    int matrizPixels[3][3];
    int matrizAvg[3][3];
    int matrizIlbp[3][3];
    //int *vetorMin[];
	
    int avg = 0;

		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				matrizPixels[i][j] = matriz[i*linhas*j];
				avg += matrizPixels[i][j];
				//printf("valoe= %d\n", matrizIlbp[i][j]);
			}
		}
        /*for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				printf("valores= %d\n", matrizIlbp[i][j]);
			}
		}*/

		avg = avg/9;
		printf("AVG: %d\n", avg);

		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++) {
				if((matrizPixels[i][j] - avg) >= 0) {
					matrizAvg[i][j] = 1;
				}
				else {
					matrizAvg[i][j] = 0;
				}
			}
		}
        
        puts("Matriz AVG: ");
		 for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
		 		printf("%d", matrizAvg[i][j]);
		 	}
		 }
        puts("\n");

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                
                matrizIlbp[i][j] = matrizAvg[i][j];

                if(i == 1 && j == 0){
                    matrizIlbp[i][j] = matrizAvg[i+1][j+2];
                }
                if(i == 1 && j == 1){
                    matrizIlbp[i][j] = matrizAvg[i+1][j];
                }
                if(i == 1 && j == 2){
                    matrizIlbp[i][j] = matrizAvg[i+1][j-2];
                }
                if(i == 2){
                    matrizIlbp[i][j] = matrizAvg[i-1][j];
                }
            }
        }
		
        puts("Matriz ILBP: ");
		 for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
		 		printf("%d", matrizIlbp[i][j]);
		 	}
		 }
        puts("\n");

        // for(int j = 2; j >= 0; j--) {
    //     for(int i = 0; i < 3; i++) {
    //            printf("%d      ", matrizIlbp[i][j]);
    //     }
    //     printf("%c", 10);
		// }
}
