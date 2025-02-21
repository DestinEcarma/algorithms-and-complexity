# Radix Sort

This is my implementation of the Radix sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

RadixLSD(A, n):
    let B be a bucket of 10 empty list, assuming we are using a base number of 10

    let M be the maximum key in A

    let digit = 1

    while (M / digit) > 0 do
        for i = 0 to (n - 1) do
            let position = floor(A[i] / digit) mod 10

            insert A[i] into B[position]

        Combine all list in B to A

        digit = digit * 10

RadixMSD(A, li, hi, digit):
    if digit > 0 and li < hi then
        let B be a bucket of 10 empty list, assuming we are using a base number of 10

        for i = li to hi do
            let position = floor(A[i] / digit) mod 10

            insert A[i] into B[position]

        for j = 0 to 9 do
            if B[j] is not empty then
                hi = li

                for each value in B[j] do
                    insert value into A[hi]
                    increment hi

                RadixMSD(A, li, hi - 1, digit / 10)

                li = hi
```
