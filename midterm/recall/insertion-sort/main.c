#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a > *(int *)b;
}

void print_int(const void *value) {
	printf("%d", *(int *)value);
}

int main() {
	int arr[] = {9, 5, 10, 7, 3, 2, 6, 4, 1};
	int len = sizeof(arr) / sizeof(int);

	printf("Initial: ");
	print_arr(arr, len, sizeof(int), print_int);

	int *sorted = insertion_sort(arr, len, sizeof(int), cmp);

	printf("Sorted: ");
	print_arr(sorted, len, sizeof(int), print_int);

	free(sorted);

	return 0;
}
