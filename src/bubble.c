#include <stdlib.h>
#include <stdbool.h>

#include "sortlib.h"

void bubblesort(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    int end, i;

    for (end = n - 1; end > 0; end--) {

        bool aux = false;

        for(i = 0; i < end; i++) {

            void* p1 = access(vector, i    , size);
            void* p2 = access(vector, i + 1, size);

            if( (*compare)(p1, p2) > 0) {
                swap(p1, p2, size);
                aux = true;
            }
        }

        if(!aux) {
            return;
        }
    }
}
