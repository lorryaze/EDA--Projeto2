#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>

int main (void){


int array[13];
int i;
srand(time(0)); 
for ( i = 0; i < 13; i++) {     // fill array
    array[i] = i;
    printf("%d,", array[i]);
}
printf("\n done with population \n");
printf("here is the final array\n");

for ( i = 0; i < 13; i++) {    // shuffle array
    int temp = array[i];
    int randomIndex = rand() % 13;

    array[i]           = array[randomIndex];
    array[randomIndex] = temp;
}


for (int i = 0; i < 13; i++) {    // print array
    printf("%d,",array[i]);
}
}
