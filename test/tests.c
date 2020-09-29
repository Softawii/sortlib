#include <stdlib.h>
#include <stdio.h>
#include "../src/sortlib.h"

static int compara(void* a, void* b) {
    float p1 = *((float*) a);
    float p2 = *((float*) b);

    return p1 > p2;   
}


int main(void) {

    float * vector = (float *) malloc(sizeof(float) * 10);

    for(int i = 0; i < 10; i++) {
        vector[i] = rand() % 100;
        printf("%f - ", vector[i]);
    }
    printf("\n");

    bubblesort(vector, 10, sizeof(vector[0]), compara);

    for(int i = 0; i < 10; i++) {
        printf("%f - ", vector[i]);
    }
}