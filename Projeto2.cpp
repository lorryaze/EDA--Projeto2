#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


	
void matriz_asfalto(const char**);
void matriz_grama();

int main (int argc, char *argv[]){
	int i;
	
	FILE *file;
	const char *arquivos_asfalto[50]; //ponteiro com os diretorios para o caminho dos arquivos asfalto
	const char *arquivos_grama[50]; //ponteiro com os diretorios para o caminho dos arquivos grama
	char strcaminho_asfalto[30]; //string do caminho do diretorio asfalto
	char strcaminho_grama[30]; //string do caminho do diretorio  grama
	char part2[] = ".txt"; //part 2 da concatenação de strings
	
	for (i = 0; i<50; i++){
		
		if (i<9){
			char numero[] = " ";
			numero[0] = (i+1) + '0';
			
			//------------------asfalto--------------------------
			char part1asfalto[] = "DataSet\\asphalt\\asphalt_0";
			//concatenando strings 
			strcpy(strcaminho_asfalto, part1asfalto); //função de copia
			strcat(strcaminho_asfalto, numero); //concatenação
			strcat(strcaminho_asfalto, part2); //concatenação
			arquivos_asfalto[i]=strcaminho_asfalto;
			//-------------------------------------------------
			
			//-----------------grama---------------------------
			char part1grama[] = "DataSet\\grass\\grass_0";
			//concatenando strings
			strcpy(strcaminho_grama, part1grama);
			strcat(strcaminho_grama, numero);
			strcat(strcaminho_grama, part2);
			arquivos_grama[i]=strcaminho_grama; 	
			//--------------------------------------------------	

		}
		else{
			char numero[] = " ";
			numero[0] = ((i+1)/10) + '0';
			int num = ((i+1)/10)*10;
			numero[1] = ((i+1)-num) + '0';
			
			//---------------asfalto-----------------------------
			char part1asfalto[] = "DataSet\\asphalt\\asphalt_";
			//concatenando strings
			strcpy(strcaminho_asfalto, part1asfalto);
			strcat(strcaminho_asfalto, numero);
			strcat(strcaminho_asfalto, part2);
			arquivos_asfalto[i]=strcaminho_asfalto;
			//----------------------------------------------------
			
			//------------------grama------------------------
			char part1grama[] = "DataSet\\grass\\grass_";
			//concatenando strings
			strcpy(strcaminho_grama, part1grama);
			strcat(strcaminho_grama, numero);
			strcat(strcaminho_grama, part2);
			arquivos_grama[i]=strcaminho_grama; 
			//-------------------------------------------------
		}
	}
	
	for (i=0; i<50; i++){
		puts(arquivos_asfalto[i]);
		puts(arquivos_grama[i]);
	}

	
/*	char asfalto1[] = "DataSet\\asphalt\\asphalt_01.txt";
	file = fopen(asfalto1, "r");
	
	if(file==NULL){
		printf ("falhou \n");
		fclose(file);
		exit(1);
	}
	else{
		printf("arquivo aberto");
		fclose(file);
	}*/
	
	return(0);
	
}
/*
void matriz_asfalto(const char *vetor[]){
	int i;
	char part2asfalto[] = ".txt";
	
	for (i = 0; i<50; i++){
		
		if (i<9){
			char strcaminho[30];
			char numero[] = "a";
			char part1asfalto[] = "DataSet\\asphalt\\asphalt_0";
			numero[0] = (i+1) + '0';
			//concatenando strings
			strcpy(strcaminho, part1asfalto);
			strcat(strcaminho, numero);
			strcat(strcaminho, part2asfalto);
			
			vetor[i]=strcaminho; 
			puts(vetor[i]);			

		}
		else{
			char strcaminho[100];
			char numero[] = "ab";
			char part1asfalto[] = "DataSet\\asphalt\\asphalt_";
			numero[0] = ((i+1)/10) + '0';
			int num = ((i+1)/10)*10;
			numero[1] = ((i+1)-num) + '0';
			//concatenando strings
			strcpy(strcaminho, part1asfalto);
			strcat(strcaminho, numero);
			strcat(strcaminho, part2asfalto);
			
			vetor[i]=strcaminho;
			puts(vetor[i]);
		}
	}
}

void matriz_grama(){
	int i ;
	int j;
	char part2grama[] = ".txt";
	
	for (i = 0; i <50; i++){
		
		if (i<9){
			char strcaminho[100];
			char numero[] = "a";
			char part1grama[] = "DataSet\\grass\\grass_0";
			numero[0] = (i+1) + '0';
			//concatenando strings
			strcpy(strcaminho, part1grama);
			strcat(strcaminho, numero);
			strcat(strcaminho, part2grama);
			//puts(strcaminho);
		//	*(vetor_asfalto+i) = strcaminho;
		}
		else{
			char strcaminho[100];
			char numero[] = "ab";
			char part1grama[] = "DataSet\\grass\\grass_";
			numero[0] = ((i+1)/10) + '0';
			int num = ((i+1)/10)*10;
			numero[1] = ((i+1)-num) + '0';
			//concatenando strings
			strcpy(strcaminho, part1grama);
			strcat(strcaminho, numero);
			strcat(strcaminho, part2grama);
			//puts(strcaminho);
		}
	}
}	*/
