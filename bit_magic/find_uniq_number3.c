/*
 * Find the non-repeating element in an array where every element repeats thrice.
 */
#include <stdio.h>
#include <math.h> // For log2
// Time complexity = O(n)
//
// This cannot be solved with the use of XOR operator because,
// XOR property needs even elements.
//
// Approach:
//     i.   Take an array to hold 32 integers. (Each integer represents the ith bit)
//     ii.  Take each element in the given array and find the set bits in it
//          and increment the corresponding ith element in the 32 bit integer array.
//     iii. Repeat step ii on all the elements in the array
//     iv.  Walk over the 32 integer array and on each element check if the number is modulo of 3
//          if so, skip that element
//          Otherwise, set that corresponding bit on a temp variable (initialized with 0)
//      v.  Once the walk is finished, the temp variable will be the non-repeating element

int main ()
{
    int ele_array[] = { 10, 30, 20, 30, 70, 10, 30, 20, 10, 20 };
    int bit_count_array[32] = {0};
    int i, n, j, tmp, res = 0;

    n = sizeof(ele_array) / sizeof(int);

    //ii
    for (i = 0; i < n; i++) {
        tmp = ele_array[i];

#if 1
        while (tmp) {
            bit_count_array[(int)log2(tmp & ~(tmp - 1))]++;
            tmp = tmp & (tmp - 1);
        }
#else
        for (j = 0; j < 32; j++) {
            if (tmp & (1 << j)) {
                bit_count_array[j]++;
            }
        }
#endif
    }

    //iv
    for (i = 0; i < n; i++) {
        if (bit_count_array[i] % 3 == 1) {
            res = res | (1 << i);
        }
    }

    fprintf(stdout, "non-repeating element = %d\n", res);
    return 0;
}
