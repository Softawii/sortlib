#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"
#include "bubble.h"


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
