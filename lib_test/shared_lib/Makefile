
all: libmymath.so

libmymath.so: ${SRC_PATH}/mymath.c ${SRC_PATH}/mymath.h ${SRC_PATH}/mymath_logical.c ${SRC_PATH}/mymath_logical.h
	@gcc ${CFLAGS} -c -fpic ${SRC_PATH}/mymath.c -o mymath.o
	@gcc ${CFLAGS} -c -fpic ${SRC_PATH}/mymath_logical.c -o mymath_logical.o
	@gcc -shared -o libmymath.so mymath.o mymath_logical.o
clean:
	@rm -rf *.o *.so
