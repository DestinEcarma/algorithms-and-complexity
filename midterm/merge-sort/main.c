#include "./../../common/cmp.h"
#include "./../../common/print-arr.h"
#include "./../../common/stress-test.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ST_LENGTH 1000000
#define ST_TIMES 100

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted_recursion =
		merge_sort_recursion(arr, len, sizeof(int), cmp_int_l);

	printf("Sorted (Recursion): ");
	print_arr(sorted_recursion, len, sizeof(int), print_int);

	int *sorted_iterative =
		merge_sort_iterative(arr, len, sizeof(int), cmp_int_l);

	printf("Sorted (Iterative): ");
	print_arr(sorted_iterative, len, sizeof(int), print_int);

	free(sorted_recursion);
	free(sorted_iterative);

	int arrST[ST_LENGTH];

	for (size_t i = 0; i < ST_LENGTH; i++) {
		arrST[i] = rand();
	}

	printf("\nStress Test\n");
	printf("Length\t\t: %d\n", ST_LENGTH);
	printf("Times\t\t: %d\n\n", ST_TIMES);

	unsigned long time_recursion =
		stress_test_sort(&arrST, ST_LENGTH, sizeof(int), ST_TIMES,
						 merge_sort_recursion, cmp_int_l);

	unsigned long time_iterative =
		stress_test_sort(&arrST, ST_LENGTH, sizeof(int), ST_TIMES,
						 merge_sort_iterative, cmp_int_l);

	printf("Recursion\n");
	printf("Total Time (ms)\t: %lu\n", time_recursion);
	printf("Avg Time (ms)\t: %lu\n\n",
		   (unsigned long)(double)time_recursion / ST_TIMES);

	printf("Iterative\n");
	printf("Total Time (ms)\t: %lu\n", time_iterative);
	printf("Avg Time (ms)\t: %lu\n",
		   (unsigned long)(double)time_iterative / ST_TIMES);

	return 0;
}
