#include <stdbool.h>

#include "../src/utils.h"
#include "evaluator.h"

int is_ordered(void *vector, int n, int size, int (*compare)(void*,  void*)) {
    
    void *e;
    void *e_1;

    for(int i = 0; i < n - 1; i++) {
        
        e   = access(vector, i    , size);
        e_1 = access(vector, i + 1, size);

        if( (*compare)(e, e_1) == 1) {
        
            printf("VECTOR: %f, %f\n", *((float*) e),  *((float*) e_1));

            return 0;
        }
    }

    return 1;
}