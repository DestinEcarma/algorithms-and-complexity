#include "helper.h"
#include "./../../../common/utils.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heapify(void *arr, size_t len, size_t parent, size_t byte_size,
			 int (*cmp)(const void *, const void *)) {
	size_t largest = parent;
	size_t *largest_ptr = arr + largest * byte_size;

	do {
		size_t left = 2 * parent + 1;
		size_t right = left + 1;

		if (left < len && cmp(arr + left * byte_size, largest_ptr)) {
			largest = left;
			largest_ptr = arr + largest * byte_size;
		}

		if (right < len && cmp(arr + right * byte_size, largest_ptr)) {
			largest = right;
			largest_ptr = arr + largest * byte_size;
		}

		if (largest != parent) {
			swap(arr + parent * byte_size, largest_ptr, byte_size);
			parent = largest;
		}
	} while (largest != parent);
}

void *heap_sort(const void *arr, size_t len, size_t byte_size,
				int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted == NULL) {
		return NULL;
	}

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = len / 2 - 1; i != ULONG_MAX; i--) {
		heapify(sorted, len, i, byte_size, cmp);
	}

	for (size_t i = len - 1; i != ULONG_MAX; i--) {
		swap(sorted, sorted + i * byte_size, byte_size);
		heapify(sorted, i, 0, byte_size, cmp);
	}

	return sorted;
}
