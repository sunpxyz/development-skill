// create_daemon.cpp
// 2022-02-08

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>

int main()
{
    pid_t pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid != 0) {
        exit(EXIT_SUCCESS);
    }

    if (setsid() == -1) {
        return -2;
    }
    if (chdir("/") == -1) {
        return -3;
    }
    umask(0);
    for (int i = 0; i < 3; i++) {
        close(i);
    }
    open("/dev/null", O_RDWR);  //stdin
    dup(0);                     //stdout
    dup(0);                     //stderr

    return 0;
}