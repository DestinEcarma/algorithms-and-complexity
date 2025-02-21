# Bucket Sort

This is my implementation of the Bucket sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

let k be the number of buckets to use
let B be a bucket (i.e. temporary array) of k empty list (can be a linked list)

let M be 1 + the maximum key value in A

for i = 0 to (n - 1) do
    let position = floor(k * A[i] / M)

    insert sorted A[i] into B[position]

Combine all list in B to A
```
