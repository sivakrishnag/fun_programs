#include <stdio.h>      // perror(), fprintf(), snprintf()
#include <stdlib.h>     // exit()
#include <string.h>     // strlen()
#include <unistd.h>     // fork(), setsid(), chdir(), dup(), ftruncate(), getpid(), write(), sleep()
#include <errno.h>      // errno and EWOULDBLOCK
#include <signal.h>     // signal() and SIGTERM
#include <syslog.h>     // syslog() and LOG_INFO
#include <sys/file.h>   // flock()
#include <sys/types.h>  // umask()
#include <sys/stat.h>   // umask()

#define MY_DAEMON_NAME "simpled"
#define SIMPLED_PID_FILE "/var/run/simpled.pid"

int
daemonize(char *err, int len)
{
    int pid_file_fd;
    pid_t pid;
    char tmp_buf[1024];

    if ((pid_file_fd = open(SIMPLED_PID_FILE, O_CREAT|O_RDWR, 0666)) == -1) {
	snprintf (err, len, "Failed to open() %s: %s\n", SIMPLED_PID_FILE, strerror(errno));
	return 1;
    } else {
	if ((flock(pid_file_fd, LOCK_EX|LOCK_NB) == -1) && (errno == EWOULDBLOCK)) {
	    snprintf (err, len, "daemon %s detects existing daemon using "
		      "lock file '%s'\n", MY_DAEMON_NAME, SIMPLED_PID_FILE);
	    return 1;
	}
    }

    /* Set the file mode creation mask to a known value */
    umask (0);

    pid = fork();
    if (pid < 0) {
	snprintf (err, len, "%s: Can't fork\n", __FUNCTION__);
	return 1;
    } else if (pid != 0) { /* Parent */
	exit (0);
    }

    /* Only child can enter this point*/

    /* Create a new session */
    if (setsid() < 0) {
	snprintf (err, len, "%s: Can't create a new session\n", __FUNCTION__);
	return 1;
    }

    /* Change current working directory to '/' */
    if (chdir("/") < 0) {
	snprintf (err, len, "%s: Can't change directory to /\n", __FUNCTION__);
	return 1;
    }

    /* Close stdin, stdout and stderr */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    ftruncate(pid_file_fd, 0);
    snprintf(tmp_buf, sizeof(tmp_buf), "%d", getpid());
    write(pid_file_fd, tmp_buf, strlen(tmp_buf));

    return 0;
}

void sig_handler(int signo)
{
    switch (signo) {
	case SIGTERM:
	    if (access(SIMPLED_PID_FILE, F_OK) == 0) {
		unlink(SIMPLED_PID_FILE);
		exit (0);
	    }
	default:
	    break;
    }
}

int main (int argc, char **argv)
{
    char error_buf[BUFSIZ] = {0};

    if (daemonize(error_buf, sizeof(error_buf))) {
	fprintf (stderr, "%s", error_buf);
	return 1;
    }

    signal(SIGTERM, sig_handler);

    while (1) {
	sleep (10);
	syslog (LOG_INFO, "Woke up after 10secs");
    }

    return 0;
}
