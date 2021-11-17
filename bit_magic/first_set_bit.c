#include <stdio.h>

int main ()
{
    int n = 55; // 11 0111

    printf ("After retaining only first set bit in %d, res is %d\n", n, n & ~(n - 1));
    return 0;
}
