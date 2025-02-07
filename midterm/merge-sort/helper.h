#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a generic merge sort implementation
/// with recursion appraoch. Be it a integer, float, or
/// even a object/structure, this function can sort those array.
void *merge_sort_recursion(const void *arr, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *));

/// This function is a generic merge sort implementation
/// with iterative approach. Be it a integer, float, or
/// even a object/structure, this function can sort those array.
void *merge_sort_iterative(const void *arr, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *));

#endif
