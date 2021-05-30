#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int numero, i;
    srand(time(0));
    numero = 1000000;
    //printf("%d\n", numero);
    for (i=0; i< numero; i++)
        printf("%d\n", rand()%100000);
    return 0;
}