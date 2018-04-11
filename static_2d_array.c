#include <stdio.h>

int main ()
{
    int arr[3][3];

    printf ("(0,0)(%p) (0,1)(%p) (0,2)(%p)\n"
            "(1,0)(%p) (1,1)(%p) (2,2)(%p)\n"
            "(2,0)(%p) (2,1)(%p) (2,2)(%p)\n",
	    &arr[0][0], &arr[0][1], &arr[0][2],
	    &arr[1][0], &arr[1][1], &arr[1][2],
	    &arr[2][0], &arr[2][1], &arr[2][2]);

    return 0;
}
