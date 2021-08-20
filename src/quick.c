#include <stdlib.h>
#include <stdbool.h>

#include "sortlib.h"


void _qsort(void* v, int size, int left, int right, int (*compare)(void*, void*)) { 
    void *vT1, *vT2; 
    
    int last, mid = (left + right) / 2; 
    
    if (left >= right) 
        return; 
  
    void * vL = access(v, left, size); // vL -> Left
    void * vR = access(v, mid, size);  // vR -> Right

    swap(vL, vR, size); 
    
    last = left; 
    
    for (int i = left + 1; i <= right; i++) { 
  
        vT1 = access(v, i, size);

        if (compare(vL, vT1) > 0) { 
            ++last;
            vT2 = access(v, last, size);
            swap(vT1, vT2, size); 
        } 
    } 
    vT2 = access(v, last, size);
    
    swap(vL, vT2, size); 
    _qsort(v, size, left, last - 1 , compare); 
    _qsort(v, size, last + 1, right, compare); 
}

void quicksort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    
    _qsort(vector, size, 0, n - 1, compare);
}
