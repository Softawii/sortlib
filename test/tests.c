#include <stdlib.h>
#include <stdio.h>
#include "../src/sortlib.h"

#include "evaluator.h"
#include "unit_test.h"

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

    UnitTest Unit = createUnitTest(vector, 10, sizeof(vector[0]), compara, is_ordered);

    printf("\nSelection sort algorithm\n");
    bubblesort(vector, 10, sizeof(vector[0]), compara);   

    evaluateUnitTest(&Unit);

    printf("UNIT TEST: %d\n", Unit.result);

    printVector(vector, 10);
    free(vector);
}