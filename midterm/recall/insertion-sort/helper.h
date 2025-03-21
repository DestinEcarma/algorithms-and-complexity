#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a generic insertion sort implementation.
/// Be it a integer, float, or even a object/structure,
/// this function can sort those array.
void *insertion_sort(void *arr, size_t len, size_t byte_size,
					 int (*cmp)(const void *, const void *));

/// This function is a generic insertion sort implementation.
/// This function will have the same result as `insertion_sort`.
/// The only difference is that this function will sort the array from the rear.
void *insertion_sort_reverse(void *arr, size_t len, size_t byte_size,
							 int (*cmp)(const void *, const void *));

#endif
