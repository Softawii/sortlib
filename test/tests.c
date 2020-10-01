#include <stdlib.h>
#include <stdio.h>
#include "../src/sortlib.h"

static int compara(void* a, void* b) {
    float p1 = *((float*) a);
    float p2 = *((float*) b);

    if(p1 > p2)
        return 1;
    else if(p1 == p2)
        return 0;
    else
        return -1;   
}

static void printVector(float *vector, int n) {
    printf("Vector: ");
    for(int i = 0; i < n; i++) {
        if(i != n - 1)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }
    printf("\n\n");
}

static float* genVector(int length) {
    float * vector = (float *) malloc(sizeof(float) * length);

    printf("Vector: ");
    for(int i = 0; i < length; i++) {
        vector[i] = rand() % 100;
        if(i != length - 1)
            printf("%f - ", vector[i]);
        else
            printf("%f", vector[i]);
    }
    return vector;
}

int main(void) {

    float * vector;

    //------ Selecition sort ------//
    
    vector = genVector(10);

    printf("\nSelection sort algorithm\n");
    selectionsort(vector, 10, sizeof(vector[0]), compara);
    
    printVector(vector, 10);
    free(vector);

    //------ Quick sort ------//

    vector = genVector(10);
    
    printf("\nQuick sort algorithm\n");
    quicksort(vector, 10, sizeof(vector[0]), compara);

    printVector(vector, 10);
    free(vector);
    
    //------ Bubble sort ------//

    vector = genVector(10);

    printf("\nBubble sort algorithm\n");
    bubblesort(vector, 10, sizeof(vector[0]), compara);
    
    printVector(vector, 10);
    free(vector);
    
    //------ Insertion sort ------//

    vector = genVector(10);

    printf("\ninsertion sort algorithm\n");
    insertionsort(vector, 10, sizeof(vector[0]), compara);

    printVector(vector, 10);
    free(vector);


    //------ Merge sort ------//

    vector = genVector(10);

    printf("\nmerge sort algorithm\n");
    mergesort(vector, 10, sizeof(vector[0]), compara);

    printVector(vector, 10);
    free(vector);

    return 0;
}