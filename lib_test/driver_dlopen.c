#include <stdio.h>
#include <dlfcn.h>
#include "src/mymath.h"
#include "src/mymath_logical.h"

int main ()
{
    int res;
    int (*add) (int, int) = NULL;
    int (*lor) (int, int) = NULL;
    void *handle, *handle1;

    //handle1 = dlopen ("shared_lib/libmymath_dep.so", RTLD_NOW );
    /* We are opening this library with RTLD_GLOBAL because the symbols of this library
     * needs to be visbile to libmymath.so as myadd_dep() is referred in its library.
     */
    handle1 = dlopen ("shared_lib/libmymath_dep.so", RTLD_NOW | RTLD_GLOBAL);
    if (!handle1) {
	fprintf (stderr, "%s\n", dlerror());
	return 1;
    }

    //handle = dlopen ("shared_lib/libmymath.so", RTLD_LAZY | RTLD_GLOBAL);
    handle = dlopen ("shared_lib/libmymath.so", RTLD_NOW);
    if (!handle) {
	fprintf (stderr, "%s\n", dlerror());
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

/*
 * NOTES:
 * 1. Every .so file loaded dynamically will have its own symbol table.
 *	eg: libmymath_dep.so and libmymath.so in the above programs have their own symbol table.
 * 2. The mode parameter in dlopen() is mandatory and it should be one of the flags RTLD_LAZY/RTLD_NOW
 * 3. RTLD_NOW means that every symbol in the library being opened by dlopen() should be resolved.
 *	i.e, if A() is part of mylib.so and A() calls B() where B() is not part of mylib.so or in the main program,
 *	dlopen() with RTLD_NOW will fail.
 * 4. RTLD_LAZY means that the symbol resolution at the time of dlopen() is not mandatory and will be resolved
 *	at the time the symbol is referenced. If the symbol is not resolved at the time of reference, the program will exit abruptly.
 * 5. RTLD_GLOBAL is a flag which can be optionally or'd with one of the flags RTLD_NOW/RTLD_LAZY
 *	This flag means that the symbols in the .so library (symbol table) being opened will be visible to the subsequent libraries
 *	opened by dlopen().
 * 6. In case a definition for the same function is present in two libraries being opened dynamically by dlopen(), it is better to
 *	open them without RTLD_GLOBAL flag.
 * 7. In case a symbol present in the main program is needed by a symbol in shared library being loaded dynamically by dlopen(), 
 *	a linker flag -export-dynamic needs to be passed while compiling the application. Then all the symbols in the application
 *	will be visible to shared objects. -Wl,-export-dynamic
 */
