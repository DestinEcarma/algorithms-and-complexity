# Counting Sort

This is my implementation of the Counting sort algorithm in C.

## Pseudocode

```
let A be the array to be sorted
let n be the length of A

CountingSortOriginal(A, n)
    let k be the maximum value in A

    let count be an array of size k + 1
    let output be an array of size n

    for i = 0 to (n - 1) do
        let key = A[i]
        increment count[key]

    for i = 1 to k do
        increase count[i] by count[i - 1]

    for i = (n - 1) to 0 do
        let key = A[i]
        decrement count[key]
        insert key into output[count[key]]

    return output

CountingSortShifted(A, n)
    let k be the maximum value in A

    let count be an array of size k + 1
    let output be an array of size n

    for i = 0 to (n - 1) do
        if A[i] is not k then
            let key = A[i] + 1
            increment count[key]

    for i = 1 to k do
        increase count[i] by count[i - 1]

    for i = 0 to (n - 1) do
        let key = A[i]
        insert key into output[count[key]]
        increment count[key]

    return output

CountingSortMinMax(A, n)
    let min be the minimum value in A
    let max be the maximum value in A

    let count be an array of size (max - min + 1)
    let output be an array of size n

    for i = 0 to (n - 1) do
        if A[i] is not max then
            let key = A[i] - min + 1
            increment count[key]

    for i = 1 to (max - min) do
        increase count[i] by count[i - 1]

    for i = 0 to (n - 1) do
        let key = A[i] - min
        insert key into output[count[key]]
        increment count[key]

    return output
```
