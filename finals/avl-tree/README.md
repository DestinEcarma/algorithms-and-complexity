# AVL Tree

This is my implementation of the AVL tree data structure with insert and delete functions.

## Pseudocode

```
LeftRotate(*&root)
    Let *new root be the right child of root
    Let *temp be the left child of new root

    set the right child of root to temp
    set the left child of new root to root

    Update root's height to max height of children + 1
    Update new root's height to max height of children + 1

    set root to new root

RightRotate(*&root)
    Let *new root be the left child of root
    Let *temp be the right child of new root

    set the left child of root to temp
    set the right child of new root to root

    Update root's height to max height of children + 1
    Update new root's height to max height of children + 1

    set root to new root

AVLInsert(*&root, key)
    if root is NULL then
        set root to a new Node with key

    else
        if key < root's key then
            AVLInsert(left child of root, key)
        else
            AVLInsert(right child of root, key)

        Update root's height to max height of children + 1

        Let balance be the balance factor of root

        if balance > 1 then
            if balance factor of left child of root < 0 then
                LeftRotate(left child of root)
            RightRotate(root)

        else if balance < -1 then
            if balance factor of right child of root > 0 then
                RightRotate(right child of root)
            LeftRotate(root)

AVLDelete(*&root, key)
    if root is NULL then
        return

    if key < root's key then
        AVLDelete(left child of root, key)
    else if key > root's key then
        AVLDelete(right child of root, key)
    else
        if root has no left child then
            remove *root and set root to the right child of root
        else if root has no right child then
            remove *root and set root to the left child of root
        else
            Let *successor be right child of root

            while successor has a left child do
                set successor to left child of successor

            set root's key to successor's key

            AVLDelete(right child of root, successor's key)

    if root is NULL then
        return

    Update root's height to max height of children + 1

    Let balance be the balance factor of root

    if balance > 1 then
        if balance factor of left child of root < 0 then
            LeftRotate(left child of root)
        RightRotate(root)

    else if balance < -1 then
        if balance factor of right child of root > 0 then
            RightRotate(right child of root)
        LeftRotate(root)
```
