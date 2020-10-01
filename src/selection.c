#include<stdlib.h>

#include "utils.h"
#include "selection.h"

void selectionsort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    int end, i, big;
    void *p1, *p2;

    for(end = n - 1; end > 0; end--) {

        big = 0;

        for(i = 1; i <= end; i++) {

            p1 = access(vector, i  , size);
            p2 = access(vector, big, size);

            if( (*compare)(p1, p2) ) {
                big = i;
            }
        }

        p1 = access(vector, big, size);
        p2 = access(vector, end, size);
        swap(p1, p2, size);
    }
}