#include <pthread.h> // for pthread_create, pthread_join, pthread_exit
#include <stdio.h>   // for printf 

typedef struct thread_params_s {
    long int val;
    long int max;
} thread_params_t;

void *
add_thread (void *arg)
{
    long int i;
    thread_params_t *targ = (thread_params_t *)arg;
    printf ("Start of %s()\n", __FUNCTION__);

    for (i = 0; i < targ->max; i++) {
    	targ->val += 1;
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
    	targ->val -= 1;
    }

    printf ("End of %s()\n", __FUNCTION__);

    return NULL;
}

int main(int argc, char * argv[])
{
    pthread_t thread1;
    pthread_t thread2;
    thread_params_t arg = {0, 0};

    arg.val = 1;
    arg.max = 99999999;

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

    if (arg.val != 1) 
        fprintf(stdout, "\n BOOM! val is [%ld], should be %d\n", arg.val, 1);
    else
        fprintf(stdout, "\n OK! cnt is [%ld]\n", arg.val);

    return 0;
}
