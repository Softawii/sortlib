#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "../src/sortlib.h"

#include "evaluator.h"
#include "unit_test.h"

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

static int* genVectorOrdered(int length, int seed) {
    int * vector = (int *) malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++) {
        vector[i] = i;
    }
    return vector;
}

static int* genVectorReverse(int length, int seed) {
    int * vector = (int *) malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++) {
        vector[i] = length - i;
    }
    return vector;
}

static int* genVectorRandom(int length, int seed) {
    int * vector = (int *) malloc(sizeof(int) * length);

    srand(seed);

    for(int i = 0; i < length; i++) {
        vector[i] = rand() % length;
    }
    return vector;
}

UnitTest * evaluateAllMethods(int n, int seed, int* (*generator)(int, int)) {
    
    UnitTest * unit = (UnitTest *) malloc(sizeof(UnitTest) * 5);
    int * vector; 
    
    LARGE_INTEGER frequency, start, end;
    double interval;
    
    {   // selectionsort
        vector = generator(n, seed);
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        selectionsort(vector, n, sizeof(vector[0]), compareInt);
        
        QueryPerformanceCounter(&end);
        
        interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
        unit[0] = createUnitTest(vector, 10, sizeof(vector[0]), compareInt, is_ordered);

        evaluateUnitTest(&unit[0], interval);

        free(vector);
    }
    
    {   // quicksort
        vector = generator(n, seed);
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        quicksort(vector, n, sizeof(vector[0]), compareInt);
        
        QueryPerformanceCounter(&end);
        
        interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
        unit[1] = createUnitTest(vector, 10, sizeof(vector[0]), compareInt, is_ordered);

        evaluateUnitTest(&unit[1], interval);

        free(vector);
    }
    
    {   // mergesort
        vector = generator(n, seed);
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        mergesort(vector, n, sizeof(vector[0]), compareInt);
        
        QueryPerformanceCounter(&end);
        
        interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
        unit[2] = createUnitTest(vector, 10, sizeof(vector[0]), compareInt, is_ordered);

        evaluateUnitTest(&unit[2], interval);

        free(vector);
    }
    
    {   // insertionsort
        vector = generator(n, seed);
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        insertionsort(vector, n, sizeof(vector[0]), compareInt);
        
        QueryPerformanceCounter(&end);
        
        interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
        unit[3] = createUnitTest(vector, 10, sizeof(vector[0]), compareInt, is_ordered);

        evaluateUnitTest(&unit[3], interval);

        free(vector);
    }
    
    {   // bubblesort
        vector = generator(n, seed);
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        bubblesort(vector, n, sizeof(vector[0]), compareInt);
        
        QueryPerformanceCounter(&end);
        
        interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
        unit[4] = createUnitTest(vector, 10, sizeof(vector[0]), compareInt, is_ordered);

        evaluateUnitTest(&unit[4], interval);

        free(vector);
    }

    return unit;    
}

void PrintUnitTest(UnitTest * unit, int n, int seed, char * metodo, char * name) {
    FILE * arq = fopen(name, "a+");
    fprintf(arq, "Testes de metodos para %d instancias usando geracao %s com a seed %d\n", n, metodo, seed);
    fprintf(arq, "SelectionSort - Result: %s : Time: %.5f\n", unit[0].result == 1 ? "OK" : "FAIL", unit[0].time);
    fprintf(arq, "QuickSort     - Result: %s : Time: %.5f\n", unit[1].result == 1 ? "OK" : "FAIL", unit[1].time);
    fprintf(arq, "MergeSort     - Result: %s : Time: %.5f\n", unit[2].result == 1 ? "OK" : "FAIL", unit[2].time);
    fprintf(arq, "InsertionSort - Result: %s : Time: %.5f\n", unit[3].result == 1 ? "OK" : "FAIL", unit[3].time);
    fprintf(arq, "BubbleSort    - Result: %s : Time: %.5f\n", unit[4].result == 1 ? "OK" : "FAIL", unit[4].time);
    fclose(arq);
}

int main(void) {
    int size[] = {100, 1000, 100000, 1000000, 10000000};
    // RANDOMICOS

    for(int i = 0; i < 5; i++) {
        UnitTest * unit = evaluateAllMethods(size[i], 123, genVectorRandom);
        PrintUnitTest(unit, size[i], 123, "randomica", "test.txt");
        free(unit);
    }
    for(int i = 0; i < 5; i++) {
        UnitTest * unit = evaluateAllMethods(size[i], 123, genVectorOrdered);
        PrintUnitTest(unit, size[i], 123, "ordenada", "test.txt");
        free(unit);
    }
    for(int i = 0; i < 5; i++) {
        UnitTest * unit = evaluateAllMethods(size[i], 123, genVectorReverse);
        PrintUnitTest(unit, size[i], 123, "reversa", "test.txt");
        free(unit);
    }
    
}
