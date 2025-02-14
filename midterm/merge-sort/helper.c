#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)

typedef struct MergeMetaData {
	size_t mid;
	size_t length;
} MergeMeta;

void merge(void *arr, void *temp, MergeMeta meta, size_t byte_size,
		   int (*cmp)(const void *, const void *)) {
	memcpy(temp, arr, meta.length * byte_size);

	size_t right_len = meta.length - meta.mid;

	size_t left_idx = 0;
	size_t right_idx = 0;
	size_t i = 0;

	while (left_idx < meta.mid && right_idx < right_len) {
		void *value = NULL;

		void *left_value = temp + left_idx * byte_size;
		void *right_value = temp + (meta.mid + right_idx) * byte_size;

		if (cmp(left_value, right_value)) {
			value = left_value;
			left_idx++;
		} else {
			value = right_value;
			right_idx++;
		}

		memcpy(arr + i++ * byte_size, value, byte_size);
	}

	if (left_idx < meta.mid) {
		memcpy(arr + i * byte_size, temp + left_idx * byte_size,
			   byte_size * (meta.mid - left_idx));
	}

	if (right_idx < right_len) {
		memcpy(arr + (left_idx + right_idx) * byte_size,
			   temp + (meta.mid + right_idx) * byte_size,
			   byte_size * (right_len - right_idx));
	}
}

void _merge_sort_recursion(void *arr, void *temp, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *)) {
	if (len > 1) {
		MergeMeta meta = {.mid = len / 2, .length = len};

		_merge_sort_recursion(arr, temp, meta.mid, byte_size, cmp);
		_merge_sort_recursion(arr + meta.mid * byte_size, temp,
							  meta.length - meta.mid, byte_size, cmp);

		merge(arr, temp, meta, byte_size, cmp);
	}
}

void *merge_sort_recursion(const void *arr, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		memcpy(sorted, arr, len * byte_size);

		void *temp = malloc(len * byte_size);

		if (temp != NULL) {
			_merge_sort_recursion(sorted, temp, len, byte_size, cmp);
			free(temp);
		} else {
			free(sorted);
			sorted = NULL;
		}
	}

	return sorted;
}

void *merge_sort_iterative(const void *arr, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);

	if (sorted != NULL) {
		memcpy(sorted, arr, len * byte_size);

		void *temp = malloc(len * byte_size);

		if (temp != NULL) {
			for (size_t size = 1; size < len; size *= 2) {
				for (size_t start = 0; start < len - size; start += size * 2) {
					MergeMeta meta = {.mid = size,
									  .length = MIN(size * 2, len - start)};

					merge(sorted + start * byte_size, temp, meta, byte_size,
						  cmp);
				}
			}

			free(temp);
		} else {
			free(sorted);
			sorted = NULL;
		}
	}

	return sorted;
}
