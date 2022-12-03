// clean_subprocess.cpp
// 2022-02-08

#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t childExitStatus;

extern "C" {
    void cleanUp(int sigNum) {
        int status;
        wait(&status);
        childExitStatus = status;
    }
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &cleanUp;
    sigaction(SIGCHLD, &sa, NULL);

    return 0;
}