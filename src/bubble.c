#include <stdlib.h>
#include <stdbool.h>

#include "bubble.h"

static void* access(void * vector, int i, int size) {
    char* t = (char*) vector; 
    t += size * i;

    return (void*) t;
}

static void swap(void* a, void* b, int size) {
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i; 
    for (i = 0; i < size; i++) { 
        char temp = v1[i]; 
        v1[i] = v2[i]; 
        v2[i] = temp;
    } 
}

/*
 * void *vector: a pointer to the first element of a vector.
 * int n: number of vector elements.
 * int size: size in bytes of a element.
 * int compare: pointer to a comparative function.
 */
void bubblesort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    int end, i;

    for (end = n - 1; n > 0; n--) {

        bool aux = false;

        for(i = 0; i < end; i++) {

            void* p1 = access(vector, i    , size);
            void* p2 = access(vector, i + 1, size);

            if( (*compare)(p1, p2) ) {
                swap(p1, p2, size);
                aux = true;
            }
        }

        if(!aux) {
            return;
        }
    }
}
