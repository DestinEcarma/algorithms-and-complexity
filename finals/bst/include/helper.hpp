#pragma once

#include "../../common/doubly-node.hpp"

template <typename T> void bst_insert(DoublyNode<T> *&root, const T &value);
template <typename T> void bst_delete(DoublyNode<T> *&root, const T &value);
