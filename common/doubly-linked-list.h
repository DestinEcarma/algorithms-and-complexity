#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>

typedef struct DNode {
	struct DNode *left;
	struct DNode *right;
	unsigned char value[];
} DNode;

static inline void _print_dll(DNode *head,
							  void (*formatter)(const unsigned char *)) {
	if (head != NULL) {
		_print_dll(head->left, formatter);
		formatter(head->value);
		printf(" ");
		_print_dll(head->right, formatter);
	}
}

/// This function is used to print the doubly linked list using the infix
/// traversal.
static inline void print_dll(DNode *head,
							 void (*formatter)(const unsigned char *)) {
	_print_dll(head, formatter);
	printf("\n");
}

/// A function to display a integer onto the stdout/console.
static inline void print_dll_int(const unsigned char *value) {
	printf("%d", *(int *)value);
}

#endif
