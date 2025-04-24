#pragma once

#include <ostream>
#include <string>

template <typename T, typename N> class DoublyLinkedList {
  public:
    T value;
    N *left = nullptr;
    N *right = nullptr;

    DoublyLinkedList(const T &value) : value(value) {}

    std::string to_string() const {
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

    friend std::ostream &operator<<(std::ostream &os,
                                    const DoublyLinkedList<T, N> &root) {
        os << root.to_string();

        return os;
    }
};
