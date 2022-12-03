// test_fork.cpp
// 2022-02-08

#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    std::cout << "the main program process ID is " << (int)getpid() << std::endl;
    pid_t childPid = fork();
    if (childPid != 0) {
        std::cout << "this is the parent process, with id " << (int)getpid() << std::endl;
        std::cout << "the child's process ID is " << childPid << std::endl;
    } else {
        std::cout << "this is the child process, with id " << (int)getpid() << std::endl;
    }

    return 0;
}