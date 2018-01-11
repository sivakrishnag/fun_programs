/*
 * This implementation of popen and pclose are copied from the book  "Advanced Programming in the Unix Environment"
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

static pid_t *childpid = NULL;

static int maxfd;

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

long
open_max(void)
{
    if (openmax == 0) {
	errno = 0;
	if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
	    if (errno == 0)
		openmax = OPEN_MAX_GUESS;
	    else
		fprintf (stderr, "sysconf error for _SC_OPEN_MAX");
	}
    }

    return openmax;
}

FILE *
my_popen (const char *cmdstring, const char *type)
{
    int i;
    int pfd[2];
    pid_t pid;
    FILE *fp;

    /* only allow "r" or "w" */
    if ((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
	errno = EINVAL;
	return NULL;
    }

    if (childpid == NULL) {
	maxfd = open_max();
	if ((childpid = calloc(maxfd, sizeof(pid_t))) == NULL) {
	    return NULL;
	}
    }

    if (pipe(pfd) < 0) {
	return NULL;
    }

    if (pfd[0] >= maxfd || pfd[1] >= maxfd) {
	close(pfd[0]);
	close(pfd[1]);
	errno = EMFILE;
	return NULL;
    }

    if ((pid = fork()) < 0) {
	return NULL;
    } else if (pid == 0) {
	if (*type == 'r') {
	    close(pfd[0]);
	    if (pfd[1]  != STDOUT_FILENO) {
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[0]);
	    }
	} else {
	    close(pfd[1]);
	    if (pfd[0] != STDIN_FILENO) {
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[0]);
	    }
	}

	for (i = 0; i < maxfd; i++) {
	    if (childpid[i] > 0)
		close(i);
	}

	execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
	_exit(127);
    }

    if (*type == 'r') {
	close(pfd[1]);
	if ((fp = fdopen(pfd[0], type)) == NULL)
	    return NULL;
    } else {
	close(pfd[0]);
	if ((fp = fdopen(pfd[1], type)) == NULL)
	    return NULL;
    }

    childpid[fileno(fp)] = pid;
    return fp;
}

int
my_pclose(FILE *fp)
{
    int fd, stat;
    pid_t pid;

    if (childpid == NULL) {
	errno = EINVAL;
	return -1;
    }
    
    fd = fileno(fp);
    if (fd >= maxfd) {
	errno = EINVAL;
	return -1;
    }

    if ((pid = childpid[fd]) == 0) {
	errno = EINVAL;
	return -1;
    }

    childpid[fd] = 0;
    if (fclose(fp) == EOF)
	return -1;

    while (waitpid(pid, &stat, 0) < 0) {
	if (errno != EINTR) {
	    return -1;
	}
    }

    return stat;
}

int main ()
{
    FILE *fpin;
    char line[BUFSIZ];

    if ((fpin = my_popen("./misc/print_from_1_to_n_with_sleep1.sh",  "r")) == NULL) {
        fprintf (stderr, "popen error\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, BUFSIZ, fpin) != NULL) {
        fprintf (stdout, "Read %s", line);
    }

    if (my_pclose(fpin) == -1) {
        fprintf (stderr, "pclose error\n");
        exit(EXIT_FAILURE);
    }

    fprintf (stdout, "About to exit\n");

    exit(EXIT_SUCCESS);
}
