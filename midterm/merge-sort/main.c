#include "./../../common/cmp.h"
#include "./../../common/print-arr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

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

	return 0;
}
