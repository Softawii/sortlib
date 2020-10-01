#include <stdlib.h>

#include "utils.h"
#include "insertion.h"


void insertionsort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    int i, j;
    void *key;
    void* vJ;
    for( i = 1; i < n; i++) { 
        j = i - 1;
        key = get(vector,i,size);
        vJ = get(vector, j, size);
        while(j >= 0 && (*compare)(vJ, key)) {
            set(vector, j+1, size, vJ);
            j--;
            vJ = get(vector, j, size);
        }
        set(vector, j+1, size, key);
        free(key);
    }
}
