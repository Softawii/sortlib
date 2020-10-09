#include <stdlib.h>
#include <string.h>

#include "comparator.h"

int compareInt(void * a, void * b) {
    int p1 = *((int*) a);
    int p2 = *((int*) b);

    if(p1 > p2)
        return 1;
    else if(p1 == p2)
        return 0;
    else
        return -1; 
}

int compareFloat(void * a, void * b) {
    float p1 = *((float*) a);
    float p2 = *((float*) b);

    if(p1 > p2)
        return 1;
    else if(p1 == p2)
        return 0;
    else
        return -1; 
}

int compareDouble(void * a, void * b) {
    double p1 = *((double*) a);
    double p2 = *((double*) b);

    if(p1 > p2)
        return 1;
    else if(p1 == p2)
        return 0;
    else
        return -1; 
}