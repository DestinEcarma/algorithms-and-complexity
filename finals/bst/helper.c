#include "helper.h"
#include <stdlib.h>
#include <string.h>

void bst_insert(DNode **root, const void *value, size_t byte_size,
				int (*cmp)(const DNode *, const DNode *)) {
	DNode *node = malloc(sizeof(DNode) + byte_size);

	if (node == NULL) {
		return;
	}

	memcpy(node->value, value, byte_size);
	node->left = NULL;
	node->right = NULL;

	while (*root != NULL) {
		if (cmp(node, *root)) {
			root = &(*root)->left;
		} else {
			root = &(*root)->right;
		}
	}

	*root = node;
}

void _bst_delete_min(DNode **root) {
	if (*root == NULL) {
		return;
	}

	if ((*root)->left == NULL) {
		DNode *temp = (*root)->right;
		free(*root);
		*root = temp;
	} else {
		_bst_delete_min(&(*root)->left);
	}
}

void _bst_delete(DNode **root, const DNode *value, size_t byte_size,
				 int (*diff)(const DNode *, const DNode *)) {
	// The same as (a - b)
	int res = diff(value, *root);

	if (res < 0) {
		// If the difference of value and root is less than 0, then check the
		// left subtree.
		bst_delete(&(*root)->left, value, byte_size, diff);
	} else if (res > 0) {
		// If the difference of value and root is greater than 0, then check the
		// right subtree.
		bst_delete(&(*root)->right, value, byte_size, diff);
	} else {
		// If the difference of value and root is equal to 0, then delete the
		// root node.

		if ((*root)->left == NULL && (*root)->right == NULL) {
			free(*root);
			*root = NULL;
		} else if ((*root)->left == NULL) {
			DNode *temp = (*root)->right;
			free(*root);
			*root = temp;
		} else if ((*root)->right == NULL) {
			DNode *temp = (*root)->left;
			free(*root);
			*root = temp;
		} else {
			DNode *successor = (*root)->right;

			while (successor->left != NULL) {
				successor = successor->left;
			}

			memcpy((*root)->value, successor->value, byte_size);
			_bst_delete_min(&(*root)->right);
		}
	}
}

void bst_delete(DNode **root, const void *value, size_t byte_size,
				int (*diff)(const DNode *, const DNode *)) {
	DNode temp;

	memcpy(temp.value, value, byte_size);

	_bst_delete(root, &temp, byte_size, diff);
}
