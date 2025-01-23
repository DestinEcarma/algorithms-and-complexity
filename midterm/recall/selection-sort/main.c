#include "./../../../common/print-arr.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a < *(int *)b;
}

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted_normal = selection_sort(arr, len, sizeof(int), cmp);

	printf("Sorted (Normal): ");
	print_arr(sorted_normal, len, sizeof(int), print_int);

	int *sorted_reverse = selection_sort_reverse(arr, len, sizeof(int), cmp);

	printf("Sorted (Reverse): ");
	print_arr(sorted_reverse, len, sizeof(int), print_int);

	free(sorted_reverse);

	return 0;
}
