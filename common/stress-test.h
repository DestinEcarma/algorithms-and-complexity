#ifndef STRESS_TEST_H
#define STRESS_TEST_H

#include <stdlib.h>
#include <time.h>

/// This function is used to stress test a sorting algorithm.
static inline unsigned long
stress_test_sort(const void *arr, size_t len, size_t byte_size, size_t nt,
				 void *(*sort)(const void *, size_t, size_t,
							   int (*)(const void *, const void *)),
				 int (*cmp)(const void *, const void *)) {
	clock_t start = clock();

	for (size_t _ = 0; _ < nt; _++) {
		free(sort(arr, len, byte_size, cmp));
	}

	return (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
}

#endif
