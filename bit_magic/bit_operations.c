/*
 * 1. Find ith bit
 * 2. Set ith bit
 * 3. Clear ith bit
 * 4. Find first set bit index from right
 * 5. Find # of bits to change to convert a to b
 */

#include <stdio.h>
#include <math.h> //For log2

int
find_ith_bit(int num, int i)
{
    return (num >> i) & 0x1;
}

int
set_ith_bit(int num, int i)
{
    return num | (1 << i);
}

int
clear_ith_bit(int num, int i)
{
    return num & ~(1 << i);
}

int num_bits (int n)
{
    int count = 0;

    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int first_set_bit_index (int n)
{
    return log2(n & ~(n - 1));
}

int main ()
{
    int num = 22; //0001 0110
    int i = 4;
    int a, b, res;

    //1. Find ith bit (4)
    fprintf(stdout, "In num %d, %dth bit = %d\n", num, i, find_ith_bit(num, i));

    i = 3;
    //2. Set ith bit
    fprintf(stdout, "num = %d, After setting %drd bit, num = %d\n", num, i, set_ith_bit(num, i));

    i = 3;
    num = 30;
    //3. Clear ith bit
    fprintf(stdout, "num = %d, After clearing %drd bit, num = %d\n", num, i, clear_ith_bit(num, i));

    num=48; // 0011 0000
    num=49; // 0011 0001
    //4. Find the first set bit index from right
    fprintf(stdout, "First set bit index of %d is %d\n", num, first_set_bit_index(num));

    a = 22; // 0001 0110
    b = 27; // 0001 1011
    //5. Find # of bits to change to convert a to b
    //Steps:
    //    i.  XOR two numbers
    //    ii. Find count of set bits
    res = a ^ b; // 1 0 1 1 0
                 // 1 1 0 1 1
                 //------------
                 // 0 1 1 0 1

    // Now count the set bits in res
    fprintf(stdout, "Num of bits needed to convert %d to %d = %d\n", a, b, num_bits(res));

    return 0;
}
