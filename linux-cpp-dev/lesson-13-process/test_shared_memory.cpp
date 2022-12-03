// test_shared_memory.cpp
// 2022-02-08

#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
    struct shmid_ds shmbuf;
    int seg_size;
    const int shared_size = 0x6400;
    int seg_id = shmget(IPC_PRIVATE, shared_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    char *sharedMemory = (char*)shmat(seg_id, 0, 0);
    printf("Shared memory attached at %p\n", sharedMemory);
    shmctl(seg_id, IPC_STAT, &shmbuf);
    seg_size = shmbuf.shm_segsz;
    printf("Segment size: %d\n", seg_size);
    sprintf(sharedMemory, "Hello World");
    shmdt(sharedMemory);
    sharedMemory = (char*)shmat(seg_id, (void*)0x5000000, 0);
    printf("Shared memory reattached at %p\n", sharedMemory);
    printf("%s\n", sharedMemory);
    shmdt(sharedMemory);
    shmctl(seg_id, IPC_RMID, 0);

    return 0;
}