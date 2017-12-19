
CFLAGS += -pthread -Wall -Werror

all: pthread_mutex

pthread_mutex: pthread_mutex.c
	gcc pthread_mutex.c -o pthread_mutex ${CFLAGS}
	gcc pthread_bad_cnt.c -o pthread_mutex_bad_cnt ${CFLAGS}
	gcc pthread_semaphore_mutex.c -o pthread_semaphore_mutex ${CFLAGS}

clean:
	rm -rf pthread_mutex
	rm -rf pthread_mutex_bad_cnt
	rm -rf pthread_semaphore_mutex
