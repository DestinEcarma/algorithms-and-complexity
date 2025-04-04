#pragma once

#include <string>

template <typename T, typename N = void> class DoublyLinkedList;

template <typename T>
class DoublyLinkedList<T, void>
    : public DoublyLinkedList<T, DoublyLinkedList<T>> {};

template <typename T, typename N> class DoublyLinkedList {
  public:
    T value;
    N *left = nullptr;
    N *right = nullptr;

    DoublyLinkedList(const T &value) : value(value) {}

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
