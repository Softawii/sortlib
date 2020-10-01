#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"
#include "quick.h"

void quicksort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    if(n <= 1)
        return;
    
    void* x = access(vector, 0, size);
    int a = 1;
    int b = n - 1;

    void* vA;
    void* vB;

    do {
        vA = access(vector, a, size);
        while(a < n && (* compare)(vA, x) <= 0) {
            a++;
            vA = access(vector, a, size);
        }
        vB = access(vector, b, size);
        while( (*compare)(vB, x) == 1) {
            b--;
            vB = access(vector, b, size);
        }

        if(a < b) {
            swap(vA, vB, size);
            a++; b++;
            vA = access(vector, a, size);
            vB = access(vector, b, size);

        }
    } while(a <= b);

    swap(x, vB, size);

    quicksort(vector, b, size, compare);
    quicksort(vA, n - a, size, compare);

}
