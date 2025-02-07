#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *shell_sort(const void *arr, size_t len, size_t byte_size,
				 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t gap = len / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < len; i++) {
			memcpy(temp, sorted + i * byte_size, byte_size);

			size_t j = i;

			while (j >= gap && cmp(sorted + (j - gap) * byte_size, temp)) {
				memcpy(sorted + j * byte_size, sorted + (j - gap) * byte_size,
					   byte_size);
				j -= gap;
			}

			memcpy(sorted + j * byte_size, temp, byte_size);
		}
	}

	return sorted;
}
