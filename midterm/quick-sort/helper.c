#include "helper.h"
#include "./../../common/utils.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MetaData {
	size_t low;
	size_t high;
} MetaData;

void _quick_sort_lomuto(void *arr, MetaData meta, size_t byte_size,
						int (*cmp)(const void *, const void *)) {
	if (meta.low < meta.high && meta.high < ULONG_MAX) {
		void *pivot = arr + meta.high * byte_size;

		size_t i = meta.low;

		for (size_t j = meta.low; j < meta.high; j++) {
			if (cmp(arr + j * byte_size, pivot)) {
				swap(arr + i++ * byte_size, arr + j * byte_size, byte_size);
			}
		}

		swap(arr + i * byte_size, pivot, byte_size);

		_quick_sort_lomuto(arr, (MetaData){meta.low, i - 1}, byte_size, cmp);
		_quick_sort_lomuto(arr, (MetaData){i + 1, meta.high}, byte_size, cmp);
	}
}

void *quick_sort_lomuto(const void *arr, size_t len, size_t byte_size,
						int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		_quick_sort_lomuto(memcpy(sorted, arr, len * byte_size),
						   (MetaData){0, len - 1}, byte_size, cmp);
	}

	return sorted;
}

void _quick_sort_hoare(void *arr, MetaData meta, size_t byte_size,
					   int (*cmp)(const void *, const void *)) {
	if (meta.low < meta.high && meta.high < ULONG_MAX) {
		void *pivot = arr + meta.high * byte_size;

		size_t i = meta.low;
		size_t j = meta.high;

		while (i < j) {
			while (cmp(arr + i * byte_size, pivot)) {
				i++;
			}

			while (cmp(pivot, arr + j * byte_size)) {
				j--;
			}

			if (i < j) {
				swap(arr + i++ * byte_size, arr + j-- * byte_size, byte_size);
			}
		}

		_quick_sort_hoare(arr, (MetaData){meta.low, i - 1}, byte_size, cmp);
		_quick_sort_hoare(arr, (MetaData){i, meta.high}, byte_size, cmp);
	}
}

void *quick_sort_hoare(const void *arr, size_t len, size_t byte_size,
					   int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		_quick_sort_hoare(memcpy(sorted, arr, len * byte_size),
						  (MetaData){0, len - 1}, byte_size, cmp);
	}

	return sorted;
}
