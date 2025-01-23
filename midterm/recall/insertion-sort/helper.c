#include "helper.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *insertion_sort(void *arr, size_t len, size_t byte_size,
					 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = 1; i < len; i++) {
		memcpy(temp, sorted + i * byte_size, byte_size);

		size_t j = i;

		while (j > 0 && cmp(sorted + (j - 1) * byte_size, temp)) {
			memcpy(sorted + j * byte_size, sorted + (j - 1) * byte_size,
				   byte_size);
			j--;
		}

		memcpy(sorted + j * byte_size, temp, byte_size);
	}

	free(temp);

	return sorted;
}

void *insertion_sort_reverse(void *arr, size_t len, size_t byte_size,
							 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = len - 1; i > 0; i--) {
		memcpy(temp, sorted + (i - 1) * byte_size, byte_size);

		size_t j = i;

		while (j < len && !cmp(sorted + j * byte_size, temp)) {
			memcpy(sorted + (j - 1) * byte_size, sorted + j * byte_size,
				   byte_size);
			j++;
		}

		memcpy(sorted + (j - 1) * byte_size, temp, byte_size);
	}

	free(temp);

	return sorted;
}
