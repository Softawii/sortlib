#ifndef SORTLIB_BUBBLE_H
#define SORTLIB_BUBBLE_H

/**
 * Sort a vector using bubble sort algorithm.
 * 
 * @param vector        Pointer to the vector to be sorted.
 * @param n             Vector size in elements.
 * @param size          Element size in bytes.
 * @param compare       Pointer to the function that 
 *                      compares the vector elements.
 * 
 */

void bubblesort(void *vector, int n, int size, int (*compare)(void*,  void*));

#endif
