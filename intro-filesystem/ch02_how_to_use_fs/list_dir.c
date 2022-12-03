/*
 * ch02_how_to_use_fs/list_dir.c
 * 2022/03/15
 */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
    DIR *dir;
    struct dirent *ptr;

    dir = opendir("./");
    while ((ptr = readdir(dir)) != NULL) {
        printf("%s\n", ptr->d_name);
    }
    closedir(dir);

    return 0;
}