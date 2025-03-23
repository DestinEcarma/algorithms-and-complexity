# Binary Search Tree

This is my implementation of the binary search tree data structure with insert and delete functions.

## Pseudocode

```
BSTInsert(**root, key)
    Let *node = new Node(key)

    set left and right of node to NULL

    while *root is not NULL do
        if key < current root's key then
            set root to the address of left of root
        else
            set root to the address of right of root

    set *root to node

BSTDeleteMin(**root)
    if *root is not NULL then
        if *root has no left child then
            remove *root and set *root to the right child of root
        else
            BSTDeleteMin(address of left of root)

BSTDelete(**root, key)
    if key < root's key then
        BSTDelete(address of left of root, key)
    else if key > root's key then
        BSTDelete(address of right of root, key)
    else
        if *root has no left child then
            remove *root and set *root to the right child of root
        else if *root has no right child then
            remove *root and set *root to the left child of root
        else
            Let *successor be the right child of *root

            while successor has a left child do
                set successor to the left child of successor

            set the key of *root to the key of successor
            BSTDeleteMin(address of right of root)
```
