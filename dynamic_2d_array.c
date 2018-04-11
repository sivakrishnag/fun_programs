#include <stdio.h>
#include <stdlib.h>

int *
alloc (int r, int c)
{
    return ((int *)malloc (sizeof (int) * r * c));
}

int
get_value (int *arr, int i, int j, int c)
{
    return  *(arr + i * c + j);
}

int *
get_address (int *arr, int i, int j, int c)
{
    return  (arr + i * c + j);
}

void
set_value (int *arr, int i, int j, int c, int value)
{
    *(arr + i * c + j) = value;
}

int main ()
{
    int *ptr, r = 2, c = 3;

    // array[2][3]
    ptr  = alloc (r, c);

    set_value (ptr, 0, 0, c, 0);
    set_value (ptr, 0, 1, c, 1);
    set_value (ptr, 0, 2, c, 2);
    set_value (ptr, 1, 0, c, 3);
    set_value (ptr, 1, 1, c, 4);
    set_value (ptr, 1, 2, c, 5);

    printf ("ptr[0][0] = %d(%p)\n"
	    "ptr[0][1] = %d(%p)\n"
	    "ptr[0][2] = %d(%p)\n"
	    "ptr[1][0] = %d(%p)\n"
	    "ptr[1][1] = %d(%p)\n"
	    "ptr[1][2] = %d(%p)\n",
	    get_value (ptr, 0, 0, c), get_address (ptr, 0, 0, c),
	    get_value (ptr, 0, 1, c), get_address (ptr, 0, 1, c),
	    get_value (ptr, 0, 2, c), get_address (ptr, 0, 2, c),
	    get_value (ptr, 1, 0, c), get_address (ptr, 1, 0, c),
	    get_value (ptr, 1, 1, c), get_address (ptr, 1, 1, c),
	    get_value (ptr, 1, 2, c), get_address (ptr, 1, 2, c));

    return 0;
}
