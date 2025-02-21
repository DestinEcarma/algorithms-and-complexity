#include "helper.h"
#include "./../../common/utils.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *gnome_sort(const void *arr, size_t len, size_t byte_size,
				 int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		memcpy(sorted, arr, len * byte_size);

		size_t i = 1;

		while (i < len) {
			if (cmp(sorted + i * byte_size, sorted + (i - 1) * byte_size)) {
				i++;
			} else {
				swap(sorted + i * byte_size, sorted + (i - 1) * byte_size,
					 byte_size);

				if (i > 1) {
					i--;
				}
			}
		}
	}

	return sorted;
}

void *gnome_sort_memo(const void *arr, size_t len, size_t byte_size,
					  int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		memcpy(sorted, arr, len * byte_size);

		size_t i = 1;

		while (i < len) {
			if (cmp(sorted + i * byte_size, sorted + (i - 1) * byte_size)) {
				i++;
			} else {
				size_t prev = i;

				while (!cmp(sorted + i * byte_size,
							sorted + (i - 1) * byte_size) &&
					   i > 0) {
					swap(sorted + i * byte_size, sorted + (i - 1) * byte_size,
						 byte_size);
					i--;
				}

				i = prev + 1;
			}
		}
	}

	return sorted;
}
