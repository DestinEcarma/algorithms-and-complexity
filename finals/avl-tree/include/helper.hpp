#pragma once

#include "../../common/doubly-heighted-node.hpp"

template <typename T> void avl_insert(DoublyHNode<T> *&root, const T &value);
template <typename T> void avl_delete(DoublyHNode<T> *&root, const T &value);
