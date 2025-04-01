#pragma once

#include <string>

template <typename T> class DoublyNode {
  public:
    T value;
    DoublyNode<T> *left;
    DoublyNode<T> *right;

    DoublyNode(T value) : value(value), left(nullptr), right(nullptr) {}

    std::string to_string() {
        std::string result;

        if (left != nullptr) {
            result += left->to_string();
        }

        result += std::to_string(value) + " ";

        if (right != nullptr) {
            result += right->to_string();
        }

        return result;
    }
};
