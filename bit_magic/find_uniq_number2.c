/*
 * Find the two non-repeating elements in an array where every element repeats twice.
 */
#include <stdio.h>
// Time complexity = O(n)
//
// Approach:
//     i.   Let us say 'a' and 'b' are non-repeating elements in an array.
//     ii.  XOR all the elements in the array which results into 'a' ^ 'b'.
//     iii. Check one set bit in the result
//          This means as per XOR property,
//          one of the numbers 'a' or 'b' should have that particular bit as 0
//          and the other number should have that particular bit set to 1
//     iv.  Now do either one of the below:
//            - Check all the elements in the array and see which all elements have that bit set to 0
//            - Check all the elements in the array and see which all elements have that bit set to 1
//      v.  XOR the obtained elements with the above result and we get one of the two elements
//      vi. Now XOR this one element with the XOR result of 'a' ^ 'b' obtained in the step ii
//      vii. We would have gotten 'a' and 'b'
int main ()
{
    int ele_array[] = { 10, 20, 30, 40, 50, 30, 20, 10 };
    int i, n, all_elem_res = 0, ele_with_first_set_bit;
    int a = 0, b = 0;

    n = sizeof(ele_array) / sizeof(int);

    //ii
    for (i = 0; i < n; i++) {
        all_elem_res = all_elem_res ^ ele_array[i];
    }
    // all_elem_res = a ^ b
    printf ("all_elem_res = %d (%d ^ %d)\n", all_elem_res, 40, 50);

    //iii
    ele_with_first_set_bit = all_elem_res & ~(all_elem_res - 1);
    printf ("elem with first set bit = %d\n", ele_with_first_set_bit);

    //iv
    a = all_elem_res;
    for (i = 0; i < n; i++) {
        if (ele_array[i] & ele_with_first_set_bit) {
            printf ("%d ^ %d = %d\n", a, ele_array[i], a ^ ele_array[i]);
            a = a ^ ele_array[i];
        }
    }

    //v
    b = all_elem_res ^ a;

    fprintf(stdout, "non-repeating elements = %d and %d\n", a, b);
    return 0;
}
