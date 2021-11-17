/*
 * Find the only non-repeating element in an array where every element repeats twice.
 */
#include <stdio.h>
// Time complexity = O(n)
int main ()
{
    int ele_array[] = { 10, 20, 30, 40, 30, 20, 10 };
    int i, n, res = 0;

    n = sizeof(ele_array) / sizeof(int);

    for (i = 0; i < n; i++) {
        res = res ^ ele_array[i];
    }

    fprintf(stdout, "non-repeating element = %d\n", res);
    return 0;
}
