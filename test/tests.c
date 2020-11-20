#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <omp.h>

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

/**
 * 
 *  Testes para um método específico, com um número de instâncias específico, 
 *  com um método de geração específico e uma seed específica.
 * 
 */
UnitTest evaluateMethod(int n, int seed, int* (*generator)(int, int), SortMethod methodsort) {
    
    UnitTest unit;
    int * vector; 
    
    struct timespec start, end;
    
    long double seconds, nanoseconds;
    long double interval;
      
    {   // quicksort
        vector = generator(n, seed);

        clock_gettime(CLOCK_REALTIME, &start);

        methodsort(vector, n, sizeof(vector[0]), compareInt);
        
        clock_gettime(CLOCK_REALTIME, &end);
        
        seconds = end.tv_sec - start.tv_sec;
        nanoseconds = end.tv_nsec - start.tv_nsec;

        interval = seconds + (nanoseconds * 1e-9);

        unit = createUnitTest(vector, 10, sizeof(vector[0]), compareInt, is_ordered);

        evaluateUnitTest(&unit, interval);

        free(vector);
    }
    
    return unit;    
}

void PrintUnitTest(UnitTest unit, int n, int seed, char * method, char * name) {
    char buf[1024] = "";
    
    strcat(buf, "results/");
    strcat(buf, name);
    strcat(buf, ".csv");
    
    FILE * arq = fopen(buf, "a+");

    fprintf(arq, "%s,%s,%d,%s,%.9Lf\n", name, method, n, unit.result == 1 ? "OK" : "FAIL", unit.time);
    fclose(arq);
}

void resetPrintUnitTest(char * name) {
    char buf[1024] = "";
    
    strcat(buf, "results/");
    strcat(buf, name);
    strcat(buf, ".csv");

    FILE * arq = fopen(buf, "w");

    // mergesort,random,100,OK,0.000032900 //
    fprintf(arq, "Method, Type, Instances, Status, Time\n");

    fclose(arq);
}

int main(void) {
    int size[] = {100, 1000, 100000, 1000000, 10000000};

    #pragma omp parallel num_threads(5) 
    {
        
        int n = omp_get_thread_num();
 
        if(n == 3) {
            char name[] = "mergesort";
        
            resetPrintUnitTest(name);
            for(int i = 0; i < 5; i++) {
                UnitTest unit;

                unit = evaluateMethod(size[i], 123, genVectorRandom, mergesort);
                PrintUnitTest(unit, size[i], 123, "random", name); 
                
                unit = evaluateMethod(size[i], 123, genVectorOrdered, mergesort);
                PrintUnitTest(unit, size[i], 123, "ordered", name); 

                unit = evaluateMethod(size[i], 123, genVectorReverse, mergesort);
                PrintUnitTest(unit, size[i], 123, "reverse", name); 
            }
        }            
        else if(n==4) {
            char name[] = "quicksort";

            resetPrintUnitTest(name);
            for(int i = 0; i < 5; i++) {
                UnitTest unit;
                
                unit = evaluateMethod(size[i], 123, genVectorRandom, quicksort);
                PrintUnitTest(unit, size[i], 123, "random", name); 
                
                unit = evaluateMethod(size[i], 123, genVectorOrdered, quicksort);
                PrintUnitTest(unit, size[i], 123, "ordered", name); 
                
                unit = evaluateMethod(size[i], 123, genVectorReverse, quicksort);
                PrintUnitTest(unit, size[i], 123, "reverse", name); 
                
            }
        }
        else if(n == 0)
        {
            for(int i = 0; i < 4; i++){
            char name[] = "bubblesort";
            
            UnitTest unit;
            
            unit = evaluateMethod(size[i], 123, genVectorRandom, bubblesort);
            PrintUnitTest(unit, size[i], 123, "random", name); 
            
            unit = evaluateMethod(size[i], 123, genVectorOrdered, bubblesort);
            PrintUnitTest(unit, size[i], 123, "ordered", name); 
            
            unit = evaluateMethod(size[i], 123, genVectorReverse, bubblesort);
            PrintUnitTest(unit, size[i], 123, "reverse", name);  
            }     
        }
        else if(n == 1)
        {
            for(int i = 0; i < 4; i++){
            char name[] = "selectionsort";

            UnitTest unit;

            unit = evaluateMethod(size[i], 123, genVectorRandom, selectionsort);
            PrintUnitTest(unit, size[i], 123, "random", name); 
            
            unit = evaluateMethod(size[i], 123, genVectorOrdered, selectionsort);
            PrintUnitTest(unit, size[i], 123, "ordered", name); 
            
            unit = evaluateMethod(size[i], 123, genVectorReverse, selectionsort);
            PrintUnitTest(unit, size[i], 123, "reverse", name);    
            }
        }
        else if(n == 2)
        {
            for(int i = 0; i < 4; i++) {
            char name[] = "insertionsort";

            UnitTest unit;
            
            unit = evaluateMethod(size[i], 123, genVectorRandom, insertionsort);
            PrintUnitTest(unit, size[i], 123, "random", name); 
            
            unit = evaluateMethod(size[i], 123, genVectorOrdered, insertionsort);
            PrintUnitTest(unit, size[i], 123, "ordered", name); 
            
            unit = evaluateMethod(size[i], 123, genVectorReverse, insertionsort);
            PrintUnitTest(unit, size[i], 123, "reverse", name); 
            }
        }       
    }
}
