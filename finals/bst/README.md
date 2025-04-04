# Binary Search Tree

This is my implementation of the binary search tree data structure with insert and delete functions.

## Pseudocode

```
BSTInsert(*&root, key)
    Let *node a new Node with key

    Let **trav be root

    while *trav is not NULL do
        if key < current *trav's key then
            set trav to the address of left of trav
        else
            set trav to the address of right of trav

    set *trav to node

BSTDelete(*&root, key)
    if key < root's key then
        BSTDelete(left child of root, key)
    else if key > root's key then
        BSTDelete(right child of root, key)
    else
        if root has no left child then
            remove *root and set root to the right child of root
        else if *root has no right child then
            remove *root and set root to the left child of root
        else
            Let *successor be the right child of root

            while successor has a left child do
                set successor to the left child of successor

            set the key of *root to the key of successor

            BSTDelete(right child of root, key of successor)
```
