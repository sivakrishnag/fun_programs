/*
 * A simple program to demonstrate the usage of pipe.
 * 
 * 1. Creates a pipe
 * 2. Forks the process
 *
 * PARENT:
 * 3. Closes read-end of the pipe.
 * 4. Writes numbers from 0 to COUNT to pipe.
 * 5. Close write-end of the pipe to indicate that there are no more writers to the pipe.
 * 6. Wait for the child to exit in waitpid() call.
 *
 * CHILD:
 * 7. Closes write-end of the pipe.
 * 8. Reads the contents of pipe and prints on stdout till read() returns 0.
 *    Note: i) read() returns 0 if encounters EOF. If there are no more writers, then the pipe will have EOF
 *	    ii) Trying to write() on a pipe with no readers will generate SIGPIPE signal.
 *
 * 9. Closes read-end of the pipe as we are done with it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define _GNU_SOURCE
#include <unistd.h>

#define COUNT 10

int main ()
{
    int fd[2];
    int ret, i, n;
    char buf[BUFSIZ];
    pid_t pid;
    
    /* Create a pipe */
    ret = pipe(fd);
    if (ret < 0) {
	fprintf(stderr, "Failed to create pipe:%s\n", strerror(errno));
	exit(EXIT_FAILURE);
    }

    switch (pid = fork()) {
    case -1:
	fprintf (stderr, "Failed to fork a child:%s\n", strerror(errno));
	exit(EXIT_FAILURE);
    case 0:  /* Child */
	close(fd[1]);	      /* Close read-end of the pipe */
	while ((n = read(fd[0], buf, sizeof(buf)))) {
	    buf[n] = '\0';
	    fprintf(stdout, "From Child: Read '%s' (%d) from pipe\n", buf, n);
	}
	close(fd[0]);	    /* Done with pipe, close read-end of it*/
	break;
    default: /* Parent */
	close(fd[0]);	      /* Close read-end of the pipe */
	fprintf (stdout, "Pid of parent = %d, child = %d\n", getpid(), pid);
	for (i = 0; i < COUNT; i++) {
	    n = snprintf(buf, sizeof(buf), "%d", i);
	    write(fd[1], buf, n);
	}
	close(fd[1]);	    /* Done with pipe, close write-end of it */
	if (waitpid(pid, NULL, 0) < 0) {
	    fprintf(stderr, "waitpid() error: %s\n", strerror(errno));
	    return 1;
	}
    }

    return 0;
}

