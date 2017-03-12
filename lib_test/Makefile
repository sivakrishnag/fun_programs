
CUR_DIR=$(shell pwd)
export SRC_PATH=${CUR_DIR}/src
SHARED_LIB_DIR="${CUR_DIR}/shared_lib"
STATIC_LIB_DIR="${CUR_DIR}/static_lib"
#export CFLAGS=-Werror -Wall
SRCS=${SRC_PATH}/mymath.c \
	${SRC_PATH}/mymath_dep.c \
	${SRC_PATH}/mymath_logical.c \
	${SRC_PATH}/mymath_dep.c

all: driver_static driver_shared driver_dlopen

${STATIC_LIB_DIR}/libmymath.a: ${SRCS}
	@make -C ${STATIC_LIB_DIR}

${SHARED_LIB_DIR}/libmymath.so: ${SRCS}
	@make -C ${SHARED_LIB_DIR}

driver_static: ${STATIC_LIB_DIR}/libmymath.a
	        @gcc -g ${CFLAGS} driver.c -o driver_static -lmymath -L${STATIC_LIB_DIR}

driver_shared: ${SHARED_LIB_DIR}/libmymath.so
	        @gcc -g driver.c ${CFLAGS} -o driver_shared -lmymath -lmymath_dep -L${SHARED_LIB_DIR} -Wl,-rpath=${SHARED_LIB_DIR}

driver_dlopen: ${SHARED_LIB_DIR}/libmymath.so
	        @gcc -g driver_dlopen.c ${CFLAGS} -o driver_dlopen -ldl

clean:
	@make -C ${STATIC_LIB_DIR} clean
	@make -C ${SHARED_LIB_DIR} clean
	@rm -rf driver_static driver_shared
	@rm -rf driver_dlopen
