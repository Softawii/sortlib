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

    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        vector[i] = rand() % 100;
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }

    printf("\nSelection sort algorithm\n");
    selectionsort(vector, 10, sizeof(vector[0]), compara);
    
    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }
    printf("\n\n");

    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        vector[i] = rand() % 100;
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }
    
    printf("\nQuick sort algorithm\n");
    quicksort(vector, 10, sizeof(vector[0]), compara);

    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }
    printf("\n\n");

    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        vector[i] = rand() % 100;
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }

    printf("\nBubble sort algorithm\n");
    bubblesort(vector, 10, sizeof(vector[0]), compara);
    
    printf("\n\n");

    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        vector[i] = rand() % 100;
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }

    printf("\ninsertion sort algorithm\n");
    insertionsort(vector, 10, sizeof(vector[0]), compara);

    printf("Vector: ");
    for(int i = 0; i < 10; i++) {
        if(i != 9)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }
    printf("\n\n");

    return 0;
}