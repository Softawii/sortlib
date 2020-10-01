#ifndef SORTLIB_MERGE_H
#define SORTLIB_MERGE_H

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
extern void mergesort(void *vector, int n, int size, int (*compare)(void*,  void*));

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
void merge(void *vector, int n, int size, int (*compare)(void*,  void*));

#endif