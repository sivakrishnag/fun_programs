
CUR_DIR=$(shell pwd)
export SRC_PATH=${CUR_DIR}/src
SHARED_LIB_DIR="${CUR_DIR}/shared_lib"
STATIC_LIB_DIR="${CUR_DIR}/static_lib"
#export CFLAGS=-Werror -Wall


all: ${STATIC_LIB_DIR}/libmymath.a driver_static ${SHARED_LIB_DIR}/libmymath.so driver_shared

${STATIC_LIB_DIR}/libmymath.a:
	@make -C ${STATIC_LIB_DIR}

${SHARED_LIB_DIR}/libmymath.so:
	@make -C ${SHARED_LIB_DIR}

driver_static: ${STATIC_LIB_DIR}/libmymath.a
	        @gcc -g ${CFLAGS} driver.c -o driver_static -lmymath -L${STATIC_LIB_DIR}

driver_shared: ${SHARED_LIB_DIR}/libmymath.so
	        @gcc -g driver.c ${CFLAGS} -o driver_shared -lmymath -L${SHARED_LIB_DIR} -Wl,-rpath=${SHARED_LIB_DIR}

clean:
	@make -C ${STATIC_LIB_DIR} clean
	@make -C ${SHARED_LIB_DIR} clean
	@rm -rf driver_static driver_shared
