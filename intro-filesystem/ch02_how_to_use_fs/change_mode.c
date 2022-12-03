/*
 * ch02_how_to_use_fs/change_mode.c
 * 2022/08/02
 */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int ret = 0, mode = 0;
    struct stat file_info;
    
    ret = stat("test.bin", &file_info);
    if (ret < 0) {
        printf("get file info error");
    }

    mode = file_info.st_mode | S_IRUSR;
    ret = chmod("test.bin", mode);
    if (ret < 0) {
        printf("change mode failed");
    }

    return 0;
}