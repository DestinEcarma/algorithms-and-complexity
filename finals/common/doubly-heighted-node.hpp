#pragma once

#include "doubly-linked-list.hpp"

template <typename T>
class DoublyHNode : public DoublyLinkedList<T, DoublyHNode<T>> {
  public:
    int height = 1;

    DoublyHNode(const T &value) : DoublyLinkedList<T, DoublyHNode<T>>(value) {}
};
