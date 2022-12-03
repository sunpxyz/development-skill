// local_socket_server.cpp
// 2022-02-08

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

bool serve(int clientSocket)
{
    while (true) {
        int length;
        char *msg;
        if (read(clientSocket, &length, sizeof(length)) == 0) {
            return true;
        }
        msg = new char[length];
        read(clientSocket, msg, length);
        std::cout << msg << std::endl;
        if (!strcmp(msg, "quit")) {
            delete [] msg;
            msg = NULL;
            return false;
        } else {
            delete [] msg;
            msg = NULL;
        }
    }
}

int main(int argc, char* const argv[])
{
    const char* const socketName = argv[1];
    int socketFd;
    struct sockaddr_un name;
    socketFd = socket(PF_LOCAL, SOCK_STREAM, 0);
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socketName);
    bind(socketFd, (struct sockaddr*)&name, SUN_LEN(&name));
    listen(socketFd, 5);

    bool serving = true;
    while (serving) {
        struct sockaddr_un clientName;
        socklen_t clientNameLen;
        int clientSocketFd;
        clientSocketFd = accept(socketFd, (struct sockaddr*)&clientName, &clientNameLen);
        serving = serve(clientSocketFd);
        close(clientSocketFd);
    }
    close(socketFd);
    unlink(socketName);

    return 0;
}