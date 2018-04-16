# $< = First prerequisite
# $@ = Target
# $^ = All prerequisites

CFLAGS += -pthread -Wall -Werror

all: pthread_mutex simple_daemon pipe my_popen num_bits_set

pthread_mutex: pthread_mutex.c pthread_bad_cnt.c pthread_semaphore_mutex.c tls.c
	gcc pthread_mutex.c -o pthread_mutex ${CFLAGS}
	gcc pthread_bad_cnt.c -o pthread_mutex_bad_cnt ${CFLAGS}
	gcc pthread_semaphore_mutex.c -o pthread_semaphore_mutex ${CFLAGS}
	gcc tls.c -o tls ${CFLAGS}

simple_daemon: simple_daemon.c
	gcc $< -o $@ ${CFLAGS}

pipe: pipe.c
	gcc $< -o $@ ${CFLAGS}

my_popen: my_popen.c
	gcc $< -o $@ ${CFLAGS}

num_bits_set: num_bits_set.c
	gcc $< -o $@ ${CFLAGS}

clean:
	rm -rf pthread_mutex
	rm -rf pthread_mutex_bad_cnt
	rm -rf pthread_semaphore_mutex
	rm -rf simple_daemon
	rm -rf pipe
	rm -rf my_popen
	rm -rf num_bits_set
	rm -rf tls
