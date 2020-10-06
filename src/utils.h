#include <stdlib.h>

#ifndef _SORTLIB_UTILS_H_
#define _SORTLIB_UTILS_H_ 

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

static void set(void* vector, int i, int size, void* value) {    
    char *val = (char*) value;
    char *vec = (char*) vector;
    vec += size * i;
    for(int j = 0; j < size; j++){
        vec[j] = val[j];
    }
}

static void* get(void* vector, int i, int size) {
    char *vec = (char*) vector;
    vec += size * i;
 
    char *val = malloc(size);

    for(int j = 0; j < size; j++) {
        val[j] = vec[j];
    }

    return (void*) val;
}

#endif