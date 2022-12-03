// test_pipe.cpp
// 2022-02-08

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const int BUFF_SIZE = 128;

// write msg to stream count times
void writePipe(const char *msg, int cnt, FILE *stream)
{
    for (; cnt > 0; cnt--) {
        fprintf(stream, "%s\n", msg);
        fflush(stream);
        sleep(1);
    }
}

// read from stream
void readPipe(FILE *stream)
{
    char buff[BUFF_SIZE];
    while (!feof(stream) && !ferror(stream) && fgets(buff, sizeof(buff), stream) != NULL) {
        fprintf(stdout, "Data received: \n");
        fputs(buff, stdout);
    }
}

int main()
{
    int fds[2];
    pipe(fds);

    pid_t pid = fork();
    if (pid == 0) {
        close(fds[1]);  // read only, close write end
        FILE *stream = fdopen(fds[0], "r");
        readPipe(stream);
        close(fds[0]);
    } else if (pid > 0) {
        char buff[BUFF_SIZE];
        for (int i = 0; i < BUFF_SIZE - 2; i++) {
            buff[i] = 'A' + i % 26;
        }
        buff[BUFF_SIZE - 1] = buff[BUFF_SIZE - 2] = '\0';
        close(fds[0]);
        FILE *stream = fdopen(fds[1], "w");
        writePipe(buff, 3, stream);
        close(fds[1]);
    }

    return 0;
}