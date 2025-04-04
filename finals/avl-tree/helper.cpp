#include "include/helper.hpp"

template <typename T> int height(DoublyHNode<T> *&root) {
    if (root == nullptr) {
        return 0;
    }

    return root->height;
}

template <typename T> int balance_factor(DoublyHNode<T> *&root) {
    if (root == nullptr) {
        return 0;
    }

    return height(root->left) - height(root->right);
}

template <typename T> void left_rotate(DoublyHNode<T> *&root) {
    DoublyHNode<T> *new_root = root->right;
    DoublyHNode<T> *temp = new_root->left;

    root->right = temp;
    new_root->left = root;

    // clang-format off
	root->height = std::max(height(root->left), height(root->right)) + 1;
	new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
    // clang-format on

    root = new_root;
}

template <typename T> void right_rotate(DoublyHNode<T> *&root) {
    DoublyHNode<T> *new_root = root->left;
    DoublyHNode<T> *temp = new_root->right;

    root->left = temp;
    new_root->right = root;

    // clang-format off
	root->height = std::max(height(root->left), height(root->right)) + 1;
	new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
    // clang-format on

    root = new_root;
}

template <typename T> void avl_insert(DoublyHNode<T> *&root, const T &value) {
    if (root == nullptr) {
        root = new DoublyHNode<T>(value);
    } else {
        avl_insert((value < root->value) ? root->left : root->right, value);

        root->height = std::max(height(root->left), height(root->right)) + 1;

        int balance = balance_factor(root);

        if (balance > 1) {
            if (balance_factor(root->left) < 0) {
                left_rotate(root->left);
            }

            right_rotate(root);
        } else if (balance < -1) {
            if (balance_factor(root->right) > 0) {
                right_rotate(root->right);
            }

            left_rotate(root);
        }
    }
}

template <typename T> void avl_delete(DoublyHNode<T> *&root, const T &value) {
    if (root == nullptr) {
        return;
    }

    if (value < root->value) {
        avl_delete(root->left, value);
    } else if (value > root->value) {
        avl_delete(root->right, value);
    } else {
        if (root->left == nullptr) {
            DoublyHNode<T> *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            DoublyHNode<T> *temp = root;
            root = root->left;
            delete temp;
        } else {
            DoublyHNode<T> *successor = root->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            root->value = successor->value;

            avl_delete(root->right, successor->value);
        }
    }

    if (root == nullptr) {
        return;
    }

    root->height = std::max(height(root->left), height(root->right)) + 1;

    int balance = balance_factor(root);

    if (balance > 1) {
        if (balance_factor(root->left) < 0) {
            left_rotate(root->left);
        }

        right_rotate(root);
    } else if (balance < -1) {
        if (balance_factor(root->right) > 0) {
            right_rotate(root->right);
        }

        left_rotate(root);
    }
}

template void avl_insert<int>(DoublyHNode<int> *&, const int &);
template void avl_delete<int>(DoublyHNode<int> *&, const int &);

template int height<int>(DoublyHNode<int> *&);
template int balance_factor<int>(DoublyHNode<int> *&);
template void left_rotate<int>(DoublyHNode<int> *&);
template void right_rotate<int>(DoublyHNode<int> *&);
