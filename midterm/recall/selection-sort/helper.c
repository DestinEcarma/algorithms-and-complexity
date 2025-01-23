#include "helper.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *selection_sort(void *arr, size_t len, size_t byte_size,
					 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = 1; i < len; i++) {
		size_t min_i = i;
		size_t k = i - 1;

		for (size_t j = i; j < len; j++) {
			if (cmp(sorted + j * byte_size, sorted + min_i * byte_size)) {
				min_i = j;
			}
		}

		memcpy(temp, sorted + k * byte_size, byte_size);
		memcpy(sorted + k * byte_size, sorted + min_i * byte_size, byte_size);
		memcpy(sorted + min_i * byte_size, temp, byte_size);
	}

	free(temp);

	return sorted;
}

void *selection_sort_reverse(void *arr, size_t len, size_t byte_size,
							 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t i = len - 2; i != ULONG_MAX; i--) {
		size_t max_i = i;
		size_t k = i + 1;

		for (size_t j = i; j != ULONG_MAX; j--) {
			if (!cmp(sorted + j * byte_size, sorted + max_i * byte_size)) {
				max_i = j;
			}
		}

		memcpy(temp, sorted + k * byte_size, byte_size);
		memcpy(sorted + k * byte_size, sorted + max_i * byte_size, byte_size);
		memcpy(sorted + max_i * byte_size, temp, byte_size);
	}

	free(temp);

	return sorted;
}
