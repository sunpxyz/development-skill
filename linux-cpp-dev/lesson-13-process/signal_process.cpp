// signal_process.h
// 2022-02-07

#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

sig_atomic_t siguser1Count = 0;

extern "C" {
    void onSigusr1(int signalNumber) {
        ++siguser1Count;
    }
}

int main()
{
    std::cout << "pid: " << (int)getpid() << std::endl;
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &onSigusr1;
    sigaction(SIGUSR1, &sa, NULL);
    sleep(100);
    std::cout << "SIGUSR1 counts: " << siguser1Count << std::endl;

    return 0;
}