#include <stdlib.h>

#include "sortlib.h"

void mergesort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    int mid;
    if(n > 1) {
        mid = n/2;
        mergesort(vector, mid, size, compare);
        mergesort(vector + mid*size, n - mid, size, compare);
        merge(vector, n, size, compare);
    }
}

static void merge(void *vector, int n, int size, int (*compare)(void*,  void*)) {

    int mid = n / 2;
    int i = 0, j = mid, k = 0;

    void *vI, *vJ;

    void *t = (void *) malloc(n * size);

    while(i < mid && j < n) {
        vI = access(vector, i, size);
        vJ = access(vector, j, size);

        if( (*compare)(vJ, vI) == 1) {
            set(t, k, size, vI);
            i++;
        }
        else {
            set(t, k, size, vJ);
            j++;
        }
        k++;
    }
    if(i == mid) {
        while (j < n) {
            vJ = access(vector, j, size);
            set(t, k, size, vJ);
            j++;
            k++;
        }
    }
    else {
        while (i < mid) {
            vI = access(vector, i, size);
            set(t, k, size, vI);
            i++;
            k++;
        }
    }

    for (i = 0; i < n; i++) {
        set(vector, i, size, access(t, i, size));
    }
    free(t);
}
