# Strand Sort

This is my implementation of the Strand sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

let N be a linked list

StrandSortArray(A, n)
    let sorted be an array of n elements
    let sorted len = 0

    while n > 0 do
        pop A[0] and append it to sorted, n then is decremented

        let inserted = 1

        for i = 0 to (n - 1) do
            if A[i] >= the last element of sorted then
                append A[i] to sorted
                pop A[i], n then is decremented
                increment inserted

        MergeArray(sorted, sorted len, len(sorted) + inserted)

        increase sorted len by inserted

    return sorted

StrandSortLinkedList(N)
    let sorted be an empty linked list

    while N is not empty do
        let current = N
        let sublist be an empty linked list

        pop the first element of N and append it to sublist

        while current is not empty do
            if current value >= the last node of sublist's value then
                append current value to sublist
                remove current from N
            else
                current = current next

        sorted = MergeLinkedList(sorted, sublist)

    return sorted
```
