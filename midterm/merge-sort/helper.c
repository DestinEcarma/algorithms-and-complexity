#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)

typedef struct MergeMetaData {
	size_t left_start;
	size_t left_size;
	size_t right_start;
	size_t right_size;
	size_t length;
} MergeMeta;

void merge(void *arr, void *temp, MergeMeta meta, size_t byte_size,
		   int (*cmp)(const void *, const void *)) {
	memcpy(temp, arr, meta.length * byte_size);

	size_t left_idx = 0;
	size_t right_idx = 0;
	size_t i = 0;

	while (left_idx < meta.left_size && right_idx < meta.right_size) {
		void *value = NULL;

		void *left_value = temp + left_idx * byte_size;
		void *right_value = temp + (meta.left_size + right_idx) * byte_size;

		if (cmp(left_value, right_value)) {
			value = left_value;
			left_idx++;
		} else {
			value = right_value;
			right_idx++;
		}

		memcpy(arr + i++ * byte_size, value, byte_size);
	}

	if (left_idx < meta.left_size) {
		memcpy(arr + i * byte_size, temp + left_idx * byte_size,
			   byte_size * (meta.left_size - left_idx));
	}

	if (right_idx < meta.right_size) {
		memcpy(arr + (left_idx + right_idx) * byte_size,
			   temp + (meta.left_size + right_idx) * byte_size,
			   byte_size * (meta.right_size - right_idx));
	}
}

void _merge_sort_recursion(void *arr, void *temp, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *)) {
	if (len > 1) {
		size_t mid = len / 2;

		MergeMeta meta = {.left_start = 0,
						  .left_size = mid,
						  .right_start = mid,
						  .right_size = len - mid,
						  .length = len};

		_merge_sort_recursion(arr, temp, meta.left_size, byte_size, cmp);
		_merge_sort_recursion(arr + meta.right_start * byte_size, temp,
							  meta.right_size, byte_size, cmp);

		merge(arr, temp, meta, byte_size, cmp);
	}
}

void *merge_sort_recursion(const void *arr, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(len * byte_size);

	memcpy(sorted, arr, len * byte_size);

	_merge_sort_recursion(sorted, temp, len, byte_size, cmp);

	free(temp);

	return sorted;
}

void *merge_sort_iterative(const void *arr, size_t len, size_t byte_size,
						   int (*cmp)(const void *, const void *)) {
	void *sorted = malloc(len * byte_size);
	void *temp = malloc(len * byte_size);

	memcpy(sorted, arr, len * byte_size);

	for (size_t size = 1; size < len; size *= 2) {
		for (size_t start = 0; start < len - size; start += size * 2) {
			MergeMeta meta = {.left_start = start,
							  .left_size = size,
							  .right_start = start + size,
							  .right_size = MIN(size, len - start - size),
							  .length = MIN(size * 2, len)};

			merge(sorted + start * byte_size, temp, meta, byte_size, cmp);
		}
	}

	return sorted;
}
