# Gnome Sort

This is my implementation of the Gnome sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

GnomeSort(A, n)
    let i = 1

    while i < n do
        if A[i] >= A[i - 1] then
            increment i
        else
            swap A[i] and A[i - 1]

            if i > 1 then
                decrement i

GnomeSortMemoization(A, n)
    let current = 1

    while current < n do
        if A[current] >= A[current - 1] then
            increment current
        else
            let previous = current

            whie A[current] < A[current - 1] and current > 0 do
                swap A[current] and A[current - 1]
                decrement current

            current = previous + 1
```
