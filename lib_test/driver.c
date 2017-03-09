#include <stdio.h>
#include "src/mymath.h"
#include "src/mymath_logical.h"

int main ()
{
    int res;

    res = add (10, 20);
    printf ("res = %d\n", res);

    if (res = lor (10, 20)) {
	printf ("lor result = %d\n", res);
    }
}
