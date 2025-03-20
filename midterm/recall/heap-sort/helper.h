#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

void *heap_sort(const void *arr, size_t len, size_t byte_size,
				int (*cmp)(const void *, const void *));

#endif
