#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

/// This function is a generic comb sort implementation. Be it a integer, float,
/// or even a object/structure, this function can sort those array.
void *comb_sort(const void *arr, size_t len, size_t byte_size,
				int (*cmp)(const void *, const void *));

#endif
