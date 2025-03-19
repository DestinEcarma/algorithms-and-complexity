#include "./../../common/cmp.h"
#include "./../../common/doubly-linked-list.h"
#include "helper.h"
#include <stdlib.h>

int diff_dll_int(const DNode *a, const DNode *b) {
	return (int)a->value[0] - (int)b->value[0];
}

int main() {
	DNode *root = NULL;

	for (int i = 0; i < 10; i++) {
		int x = rand() % 100;

		printf("Inserting %d\n", x);

		bst_insert(&root, &x, sizeof(int), cmp_dll_int_l);
	}

	printf("\nBST: ");
	print_dll(root, print_dll_int);

	printf("BST Root: %d\n", *(int *)root->value);

	int x = root->value[0];

	printf("\nDeleting %d\n", x);

	bst_delete(&root, &x, sizeof(int), diff_dll_int);

	printf("BST: ");
	print_dll(root, print_dll_int);

	printf("BST Root: %d\n", *(int *)root->value);

	return 0;
}
