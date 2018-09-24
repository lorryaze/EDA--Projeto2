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
	
	array = randomizar(n);
	
	for(i=0; i<50; i++){
		sarray[i] = *(array+i);
		printf("%d\n", *(sarray+i));
	}
	
	
	for(i=0; i<n;i++){
		printf("%d\n", *(array+i));
	}
	
	free(array);
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




