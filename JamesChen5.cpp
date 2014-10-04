#include "stdafx.h"

/*
Find the sum of elements in after nth iteration for below operation on array.

original array 4 6 8 3 6 sum = 27
iteration1 -2 -2 5 -3 sum = -2 (a1= a2-a1)

iteration2: 0 -7 8 sum= 1

iteration3: 7 -15 sum =-8

O(n) Solution needed

Solution
Nth coefficients can be computed as follows:
c(n,0) * a[i] - c(n, 1) * a[i+1] + c(n, 2) * a[i+2] + ... + (-1)n-1 * c(n, n) * a[i + n]
1. Calculate c(n, k)
2. Apply weighted multiplication with c(n, k)
3. Calculate sum of the multiplication
*/
void JamesChen5()
{
}