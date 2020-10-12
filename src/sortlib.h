#ifndef SORTLIB_H
#define SORTLIB_H

extern void* access(void * vector, int i, int size);

extern void swap(void* a, void* b, int size);

extern void set(void* vector, int i, int size, void* value);

extern void* get(void* vector, int i, int size);

static void merge(void *vector, int n, int size, int (*compare)(void*,  void*));


/**
 * Sort a vector using bubble sort algorithm.
 * 
 * @param vector        Pointer to the vector to be sorted.
 * @param n             Vector size in elements.
 * @param size          Element size in bytes.
 * @param compare       Pointer to the function that 
 *                      compares the vector elements.
 * @return              void.
 */
extern void bubblesort(void *vector, int n, int size, int (*compare)(void*,  void*));

/**
 * Sort a vector using insertion sort algorithm.
 *
 * @param vector        Pointer to the vector to be sorted.
 * @param n             Vector size in elements.
 * @param size          Element size in bytes.
 * @param compare       Pointer to the function that
 *                      compares the vector elements.
 * @return              void.
 */
extern void insertionsort(void *vector, int n, int size, int (*compare)(void*,  void*));

/**
 * Sort a vector using merge sort algorithm.
 *
 * @param vector        Pointer to the vector to be sorted.
 * @param n             Vector size in elements.
 * @param size          Element size in bytes.
 * @param compare       Pointer to the function that
 *                      compares the vector elements.
 * @return              void.
 */
extern void mergesort(void *vector, int n, int size, int (*compare)(void*,  void*));

/**
 * Sort a vector using quick sort algorithm.
 *
 * @param vector        Pointer to the vector to be sorted.
 * @param n             Vector size in elements.
 * @param size          Element size in bytes.
 * @param compare       Pointer to the function that
 *                      compares the vector elements.
 * @return              void.
 */
extern void quicksort(void *vector, int n, int size, int (*compare)(void*,  void*));

/**
 * Sort a vector using selection sort algorithm.
 * 
 * @param vector        Pointer to the vector to be sorted.
 * @param n             Vector size in elements.
 * @param size          Element size in bytes.
 * @param compare       Pointer to the function that 
 *                      compares the vector elements.
 * @return              void.
 */
extern void selectionsort(void *vector, int n, int size, int (*compare)(void*,  void*));

#endif