#include "helper.h"
#include <stdlib.h>
#include <string.h>

void *shell_sort(const void *arr, size_t len, size_t byte_size,
				 int (*cmp)(const void *, const void *)) {
	// This section is to initialize the necessary dynamic memory. This approach
	// of having multiple return statements is not recommended by Ma'am P, but
	// this prevents having nested blocks. I will be doing this approach for all
	// of the algorithms.

	void *sorted = malloc(len * byte_size);

	if (sorted == NULL) {
		return NULL;
	}

	memcpy(sorted, arr, len * byte_size);

	unsigned char temp[byte_size];

	for (size_t gap = len / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < len; i++) {
			memcpy(temp, sorted + i * byte_size, byte_size);

			size_t j = i;

			while (j >= gap && cmp(sorted + (j - gap) * byte_size, temp)) {

				memmove(sorted + j * byte_size, sorted + (j - gap) * byte_size,
						byte_size);
				j -= gap;
			}

			memcpy(sorted + j * byte_size, temp, byte_size);
		}
	}

	return sorted;
}
