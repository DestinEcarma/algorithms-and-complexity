#include "helper.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *tournament_sort_offline(const int *arr, size_t len) {
	int *sorted = malloc(sizeof(int) * len);

	if (sorted != NULL) {
		size_t tree_len = len * 2 - 1;

		size_t *tree = malloc(sizeof(size_t) * tree_len);

		if (tree != NULL) {
			int *temp = malloc(sizeof(int) * len);

			if (temp != NULL) {
				memcpy(temp, arr, sizeof(int) * len);

				for (size_t i = len; i <= tree_len; i++) {
					tree[i - 1] = i - len;
				}

				size_t start = tree_len - 1;

				for (size_t i = 0; i < len; i++) {
					for (size_t right = start; right > 0; right -= 2) {
						size_t left = right - 1;
						size_t parent = left / 2;

						tree[parent] = (temp[tree[left]] <= temp[tree[right]])
										   ? tree[left]
										   : tree[right];
					}

					sorted[i] = temp[tree[0]];
					temp[tree[0]] = INT_MAX;

					start = (tree_len - (len - tree[0]) - 1) / 2 * 2 + 2;
				}

				free(temp);
			} else {
				free(sorted);
				sorted = NULL;
			}

			free(tree);
		} else {
			free(sorted);
			sorted = NULL;
		}
	}

	return sorted;
}
