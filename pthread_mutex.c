/*
 * This program shows how mutex can be used to avoid
 * corrupting a shared resource (variable) when two
 * threads are simultaneously accessing it.
 */

#include <stdio.h>
#include <pthread.h>

typedef struct thread_params_s {
    long int val;
    long int max;
    pthread_mutex_t *synchronize;
} thread_params_t;

void *
add_thread (void *arg)
{
    long int i;
    thread_params_t *targ = (thread_params_t *)arg;
    printf ("Start of %s()\n", __FUNCTION__);

    for (i = 0; i < targ->max; i++) {
	pthread_mutex_lock (targ->synchronize);
    	targ->val += 1;
    	pthread_mutex_unlock (targ->synchronize);
    }

    printf ("End of %s()\n", __FUNCTION__);

    return NULL;
}

void *
sub_thread (void *arg)
{
    long int i;
    thread_params_t *targ = (thread_params_t *)arg;
    printf ("Start of %s()\n", __FUNCTION__);

    for (i = 0; i < targ->max; i++) {
	pthread_mutex_lock (targ->synchronize);
    	targ->val -= 1;
    	pthread_mutex_unlock (targ->synchronize);
    }

    printf ("End of %s()\n", __FUNCTION__);

    return NULL;
}

int main (int argc, char **argv)
{
    pthread_t thread1;
    pthread_t thread2;
    thread_params_t arg = {0, 0, 0};
    pthread_mutex_t synchronize = PTHREAD_MUTEX_INITIALIZER;

    arg.val = 1;
    arg.max = 99999999;
    arg.synchronize = &synchronize;

    if (pthread_create (&thread1, NULL, add_thread, &arg)) {
	fprintf (stderr, "Error creating thread for add_thread()\n");
	return 1;
    }

    if (pthread_create (&thread2, NULL, sub_thread, &arg)) {
	fprintf (stderr, "Error creating thread for add_thread()\n");
	return 1;
    }

    pthread_join (thread1, NULL);
    pthread_join (thread2, NULL);

    printf ("Result val = %ld\n", arg.val);
    return 0;
}
