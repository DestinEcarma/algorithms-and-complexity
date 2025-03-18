#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct Node {
	struct Node *next;
	unsigned char value[];
} Node;

/// This function is used to print the linked list.
static inline void print_ll(Node *head,
							void (*formatter)(const unsigned char *)) {
	printf("[");

	while (head != NULL) {
		formatter(head->value);

		if (head->next != NULL) {
			printf(", ");
		}

		head = head->next;
	}

	printf("]\n");
}

/// A function to display a integer onto the stdout/console.
static inline void print_ll_int(const unsigned char *value) {
	printf("%d", *(int *)value);
}

#endif
