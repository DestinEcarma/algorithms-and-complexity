#pragma once

#include "doubly-linked-list.hpp"

template <typename T>
class DoublyNode : public DoublyLinkedList<T, DoublyNode<T>> {
  public:
    DoublyNode(const T &value) : DoublyLinkedList<T, DoublyNode<T>>(value) {}
};
