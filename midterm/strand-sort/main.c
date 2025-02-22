#include "./../../common/cmp.h"
#include "./../../common/print-arr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 100000
#define ST_TIMES 100

static inline unsigned long
stress_test_sort(const void *arr, size_t len, size_t byte_size, size_t nt,
				 void *(*sort)(const void *, size_t, size_t,
							   int (*)(const void *, const void *),
							   int (*)(const void *, const void *)),
				 int (*cmp)(const void *, const void *),
				 int (*cmp_merge)(const void *, const void *)) {
	clock_t start = clock();

	for (size_t _ = 0; _ < nt; _++) {
		void *sorted = sort(arr, len, byte_size, cmp, cmp_merge);

		if (sorted != NULL) {
			free(sorted);
		}
	}

	return (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
}

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1, 8, 12, 11, 13};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial (Array): ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted_arr =
		strand_sort_array(arr, len, sizeof(int), cmp_int_geq, cmp_int_l);

	if (sorted_arr != NULL) {
		printf("Sorted (Original): ");
		print_arr(sorted_arr, len, sizeof(int), print_int);

		free(sorted_arr);
	}

	Node *sorted_ll = NULL;

	for (int i = 0; i < len; i++) {
		Node *node = malloc(sizeof(Node) + sizeof(int));

		if (node != NULL) {
			*((int *)node->value) = arr[len - i - 1];
			node->next = sorted_ll;

			sorted_ll = node;
		}
	}

	strand_sort_ll_int(&sorted_ll, cmp_ll_int_leq, cmp_ll_int_l);

	if (sorted_ll != NULL) {
		printf("Sorted (Linked List): ");
		print_ll(sorted_ll, print_ll_int);

		while (sorted_ll != NULL) {
			Node *temp = sorted_ll;
			sorted_ll = sorted_ll->next;

			free(temp);
		}
	}

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n", ST_TIMES);

	unsigned long time =
		stress_test_sort(arrST, ST_LENGTH, sizeof(int), ST_TIMES,
						 strand_sort_array, cmp_int_geq, cmp_int_l);

	printf("\nArray\n");
	printf("Total Time (ms)\t: %lu\n", time);
	printf("Avg Time (ms)\t: %lu\n", time / ST_TIMES);

	return 0;
}
