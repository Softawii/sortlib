 #ifndef SORTLIB_INSERTION_H
#define SORTLIB_INSERTION_H

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

#endif