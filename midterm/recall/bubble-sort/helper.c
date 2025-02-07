#include "helper.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *bubble_sort(void *arr, size_t len, size_t byte_size,
				  int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(byte_size);

	memcpy(sorted, arr, len * byte_size);

	bool swapped = true;

	for (size_t i = 1; i < len && swapped; i++) {
		swapped = false;

		for (size_t j = 0; j < len - i; j++) {
			size_t curr = j * byte_size;
			size_t next = curr + byte_size;

			if (cmp(sorted + curr, sorted + next)) {
				memcpy(temp, sorted + curr, byte_size);
				memcpy(sorted + curr, sorted + next, byte_size);
				memcpy(sorted + next, temp, byte_size);
				swapped = true;
			}
		}
	}

	free(temp);

	return sorted;
}
