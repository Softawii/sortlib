#ifndef _SORTLIB_UTILS_H_
#define _SORTLIB_UTILS_H_ 

void* access(void * vector, int i, int size);

void swap(void* a, void* b, int size);

void set(void* vector, int i, int size, void* value);

void* get(void* vector, int i, int size);

#endif