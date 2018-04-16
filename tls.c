/*
 * This program shows that a tls variable will have
 * its own memory per thread.
 */

#include <stdio.h>
#include <pthread.h>

static __thread int num;

void *
thread_1 (void *arg)
{
    printf ("%s(): &num = %p\n", __FUNCTION__, &num);
    return NULL;
}

void *
thread_2 (void *arg)
{
    printf ("%s(): &num = %p\n", __FUNCTION__, &num);
    return NULL;
}

int main (int argc, char **argv)
{
    pthread_t thread1, thread2;

    printf ("%s(): &num = %p\n", __FUNCTION__, &num);

    if (pthread_create (&thread1, NULL, thread_1, NULL)) {
	fprintf (stderr, "Error creating thread for add_thread()\n");
	return 1;
    }

    if (pthread_create (&thread2, NULL, thread_2, NULL)) {
	fprintf (stderr, "Error creating thread for add_thread()\n");
	return 1;
    }

    pthread_join (thread1, NULL);
    pthread_join (thread2, NULL);

    return 0;
}
