#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a generic quick sort sort implementation with lomuto's
/// partition method. Be it a integer, float, or even a object/structure, this
/// function can sort those array.
void *quick_sort_lomuto(const void *arr, size_t len, size_t byte_size,
						int (*cmp)(const void *, const void *));

/// This function is a generic quick sort sort implementation with hoare's
/// partition method. Be it a integer, float, or even a object/structure, this
/// function can sort those array.
void *quick_sort_hoare(const void *arr, size_t len, size_t byte_size,
					   int (*cmp_l)(const void *, const void *));

#endif
