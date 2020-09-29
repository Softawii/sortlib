#include <stdlib.h>

static void* access(void * vector, int i, int size) {
    char* t = (char*) vector; 
    t += size * i;

    return (void*) t;
}

static void swap(void* a, void* b, int size) {
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i; 
    for (i = 0; i < size; i++) { 
        char temp = v1[i]; 
        v1[i] = v2[i]; 
        v2[i] = temp;
    } 
}