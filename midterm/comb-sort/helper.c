#include "helper.h"
#include "./../../common/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *comb_sort(const void *arr, size_t len, size_t byte_size,
				int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		memcpy(sorted, arr, len * byte_size);

		size_t gap = len;
		bool swapped = true;

		while (gap > 1 || swapped) {
			swapped = false;
			gap = gap / 1.3;

			if (gap < 1) {
				gap = 1;
			}

			for (size_t i = 0; i < len - gap; i++) {
				if (cmp(sorted + i * byte_size,
						sorted + (i + gap) * byte_size)) {
					swap(sorted + i * byte_size, sorted + (i + gap) * byte_size,
						 byte_size);
					swapped = true;
				}
			}
		}
	}

	return sorted;
}
