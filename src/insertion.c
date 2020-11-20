#include <stdlib.h>

#include "sortlib.h"


void insertionsort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    int i, j;
    void *vJ_1;
    void* vJ;
    for( i = 1; i < n; i++) { 
        j = i;
        vJ_1 = access(vector,j-1,size);
        vJ = access(vector, j, size);
        while(j > 0 && (*compare)(vJ_1, vJ) == 1) {
            swap(vJ, vJ_1, size);
            j--;
            vJ_1 = access(vector, j - 1, size);
            vJ   = access(vector, j    , size);
        }
    }
}
