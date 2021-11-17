/*
 * Property of XOR:
 *      1. If a number is xor'd with itself, then the result will be 0 (cancelled)
 *      2. If a number is xor'd with 0, then the result will always be the number
 */

#include <stdio.h>

int main ()
{
    int a = 10, b = 20;

    fprintf (stdout, "Before swap: a = %d -- b = %d\n", a, b);
    a = a ^ b;     // a = ab
    b = a ^ b;     // b = ab ^ b = a
    a = a ^ b;     // a = ab ^ a = b
    fprintf (stdout, "After swap : a = %d -- b = %d\n", a, b);
    return 0;
}
