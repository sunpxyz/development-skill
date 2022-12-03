/*
 * ch02_how_to_use_fs/copy_file.c
 * 2022/03/15
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_LEN 4096

int main(int argc, char* argv[])
{
    int src_fd, dest_fd;
    char data_buf[BUF_LEN];
    ssize_t read_count = 0, write_count = 0;
    int ret = 0;

    // open source file with read only
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        printf("open %s error!", argv[1]);
        goto ERR_OUT;
    }

    // open destination file with write or create
    dest_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (dest_fd == -1) {
        printf("open %s error!", argv[2]);
        goto OUT;
    }

    // copy date from source to destination
    while ((read_count = read(src_fd, &data_buf, BUF_LEN)) > 0) {
        ssize_t data_remain = read_count;
        while (data_remain > 0) {
            write_count = write(dest_fd, &data_buf, data_remain);
            if (write_count < 0) {
                goto FIN_OUT;
            }
            data_remain -= write_count;
        }
    }

    if (read_count < 0 || write_count < 0) {
        printf("copy data error!");
    }

FIN_OUT:
    close(dest_fd);
OUT:
    close(src_fd);
ERR_OUT:
    return (0);
}