#ifndef SORTLIB_QUICK_H
#define SORTLIB_QUICK_H

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

#endif