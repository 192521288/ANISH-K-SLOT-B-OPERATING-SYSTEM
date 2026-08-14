#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key;
    int shmid;
    char *shm_ptr;

    key = ftok("shmfile", 65);

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1)
    {
        perror("shmget");
        return 1;
    }

    shm_ptr = (char *)shmat(shmid, NULL, 0);

    if (shm_ptr == (char *)-1)
    {
        perror("shmat");
        return 1;
    }

    strcpy(shm_ptr, "Hello, shared memory!");

    printf("Data written to shared memory: %s\n", shm_ptr);

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}