
CFLAGS += -pthread -Wall -Werror

all: pthread_mutex simple_daemon pipe

pthread_mutex: pthread_mutex.c pthread_bad_cnt.c pthread_semaphore_mutex.c
	gcc pthread_mutex.c -o pthread_mutex ${CFLAGS}
	gcc pthread_bad_cnt.c -o pthread_mutex_bad_cnt ${CFLAGS}
	gcc pthread_semaphore_mutex.c -o pthread_semaphore_mutex ${CFLAGS}

simple_daemon: simple_daemon.c
	gcc simple_daemon.c -o simple_daemon ${CFLAGS}

pipe: pipe.c
	gcc pipe.c -o pipe ${CFLAGS}

clean:
	rm -rf pthread_mutex
	rm -rf pthread_mutex_bad_cnt
	rm -rf pthread_semaphore_mutex
	rm -rf simple_daemon
	rm -rf pipe
