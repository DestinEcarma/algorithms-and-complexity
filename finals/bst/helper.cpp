#include "include/helper.hpp"

template <typename T> void bst_insert(DoublyNode<T> *&root, T value) {
    DoublyNode<T> *node = new DoublyNode<T>(value);

    // We can't use `root` here because `root` is a reference. Reference and
    // pointers are not the same thing. Reference is like giving a new name to a
    // variable.
    DoublyNode<T> **trav = &root;

    while (*trav != nullptr) {
        trav = ((*trav)->value < value) ? &(*trav)->right : &(*trav)->left;
    }

    *trav = node;
}

template <typename T> void bst_delete(DoublyNode<T> *&root, T value) {
    if (root->value < value) {
        bst_delete(root->left, value);
    } else if (root->value > value) {
        bst_delete(root->right, value);
    } else {
        if (root->left == nullptr) {
            // If there is no left child, then just replace the root with the
            // right child.
            DoublyNode<T> *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            // If there is no right child, then just replace the root witht the
            // left child.
            DoublyNode<T> *temp = root;
            root = root->left;
            delete temp;
        } else {
            // If there are both left and right child, then we need to find the
            // successor node. By doing so we can use the left subtree to find
            // the maximum value, or using the right subtree to find the minimum
            // value.

            // Here we are using the right subtree to find the minimum
            // value.
            DoublyNode<T> *parent = root;
            DoublyNode<T> *successor = root->right;

            while (successor->left != nullptr) {
                parent = successor;
                successor = successor->left;
            }

            root->value = successor->value;

            if (parent->left == successor) {
                parent->left = successor->right;
            } else {
                parent->right = successor->right;
            }

            delete successor;
        }
    }
}

template void bst_insert<int>(DoublyNode<int> *&, int);
template void bst_delete<int>(DoublyNode<int> *&, int);
