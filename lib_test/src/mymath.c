#include <stdio.h>
#include "mymath.h"
#include "mymath_dep.h"

int add (int a, int b)
{
    return myadd_dep(a, b);
}

int sub (int a, int b)
{
    return a - b;
}

int mul (int a, int b)
{
    return a * b;
}

static int div (int a, int b)
{
    return a / b;
}
