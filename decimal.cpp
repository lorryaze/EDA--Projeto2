#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int bin[]= {1,1,1,1,0};
    int dec = 0, i;

    for(i = 3; i >= 0; i--)
    {
        dec = dec + pow(2, (i+1)) * bin[i];
       // bin = bin / 10;()
    }
    printf("\nDecimal Equivalent of Binary Number: \t %d\n", dec);
    return 0;
}