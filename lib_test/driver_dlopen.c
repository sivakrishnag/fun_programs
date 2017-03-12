#include <stdio.h>
#include <dlfcn.h>
#include "src/mymath.h"
#include "src/mymath_logical.h"

int main ()
{
    int res;
    int (*add) (int, int) = NULL;
    int (*lor) (int, int) = NULL;
    void *handle;

    handle = dlopen ("shared_lib/libmymath.so", RTLD_LAZY);
    if (!handle) {
	fprintf (stderr, "%s", dlerror());
	return 1;
    }

    add = dlsym(handle, "add");
    lor = dlsym(handle, "lor");

    res = add (10, 20);
    printf ("res = %d\n", res);

    if (res = lor (10, 20)) {
	printf ("lor result = %d\n", res);
    }
    dlclose (handle);
}
