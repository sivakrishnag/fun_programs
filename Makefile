
CFLAGS += -pthread -Wall -Werror

all: pthread_mutex

pthread_mutex: pthread_mutex.c
	gcc pthread_mutex.c -o pthread_mutex ${CFLAGS}

clean:
	rm -rf pthread_mutex
