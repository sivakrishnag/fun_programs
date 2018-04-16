/*
 * Key: n & (n - 1) resets the first set bit from right in a number 'n'
 */

#include <stdio.h>
#include <stdlib.h>

int num_bits (int n)
{
    int count = 0;

    while (n) {
	count++;
	n = n & (n - 1);
    }
    return count;
}

int main (int argc, char **argv)
{
    char *end;

    if (argc != 2) {
	fprintf (stdout, "Usage: %s <num>\n", argv[0]);
	fflush (stdout);
	return 0;
    }

    printf ("Num bits = %d\n", num_bits(strtoul (argv[1], &end, 10)));

    return 0;
}
