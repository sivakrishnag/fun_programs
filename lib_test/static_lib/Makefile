
all: libmymath.a

libmymath.a: ${SRC_PATH}/mymath.c \
		${SRC_PATH}/mymath.h \
		${SRC_PATH}/mymath_logical.c \
		${SRC_PATH}/mymath_logical.h \
		${SRC_PATH}/mymath_dep.c \
		${SRC_PATH}/mymath_dep.h
	@gcc ${CFLAGS} -c ${SRC_PATH}/mymath.c -o mymath.o
	@gcc ${CFLAGS} -c ${SRC_PATH}/mymath_logical.c -o mymath_logical.o
	@gcc ${CFLAGS} -c ${SRC_PATH}/mymath_dep.c -o mymath_dep.o
	@ar rcs libmymath.a mymath.o mymath_logical.o mymath_dep.o

clean:
	@rm -rf *.a *.o
