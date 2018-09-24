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
	
	array = randomizar(n);
	
	char *array1 = (char*) array;
	
	while(array[i] != '\0'){
		printf("%d \n", array1[i]);
 		i=i+4;
	}
	
	for(i=0; i<n;i++){
		printf("%d\n", array[i]);
	}
	
	free(array);
	return 0;
}

int * randomizar(int n){
	srand(time(0)); 
	int i;
    int * array = (int *) calloc (n, sizeof (int));
    for (i = 1; i < 51; ++i) {
        array[i] = i;
    }
 	for ( i = 1; i < 51; i++) {    // shuffle array
    	int temp = array[i];
   		int randomIndex = rand() % n;
  		array[i]= array[randomIndex];
    	array[randomIndex] = temp;
	}
    return array;
}



