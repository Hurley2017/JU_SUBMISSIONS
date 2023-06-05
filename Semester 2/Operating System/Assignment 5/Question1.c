#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>
int shmid;
struct data
{
    int max;
    int min;
    float avg;
};
int generateRandomNumber()
{
    return rand() % 500;
}
struct data compute(int *arr)
{
    struct data d;
    d.max = arr[0];
    d.min = arr[0];
    d.avg = 0;
    for (int i = 0; i < 100; i++)
    {
        if (arr[i] > d.max)
        {
            d.max = arr[i];
        }
        if (arr[i] < d.min)
        {
            d.min = arr[i];
        }
        d.avg += arr[i];
    }
    d.avg /= 100;
    return d;
}
void display(struct data d)
{
    printf("Maximum: %d\n", d.max);
    printf("Minimum: %d\n", d.min);
    printf("Average: %f\n", d.avg);
}
void displayArray(int *arr)
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void createSharedMemory()
{
    shmid = shmget(IPC_PRIVATE, 100 * sizeof(int), 0666 | IPC_CREAT);
    if (shmid < 0)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }
}
int *attachSharedMemory()
{
    int *arr = (int *)shmat(shmid, 0, 0);
    if (arr == (int *)-1)
    {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }
    return arr;
}
void detachSharedMemory(int *arr)
{
    if (shmdt(arr) == -1)
    {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }
}
void createChildProcess()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error creating child process\n");
        exit(1);
    }
    else if (pid == 0)
    {
        int *arr = attachSharedMemory();
        struct data d = compute(arr);
        detachSharedMemory(arr);
        struct data *dptr = (struct data *)shmat(shmid, 0, 0);
        if (dptr == (struct data *)-1)
        {
            printf("Error attaching shared memory segment\n");
            exit(1);
        }
        *dptr = d;
        if (shmdt(dptr) == -1)
        {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }
        exit(0);
    }
    else
    {
        int *arr = attachSharedMemory();
        for (int i = 0; i < 100; i++)
        {
            arr[i] = generateRandomNumber();
        }
        printf("Displaying the generated array!\n");
        displayArray(arr);
        detachSharedMemory(arr);
        wait(NULL);
        struct data *dptr = (struct data *)shmat(shmid, 0, 0);
        if (dptr == (struct data *)-1)
        {
            printf("Error attaching shared memory segment\n");
            exit(1);
        }
        display(*dptr);
        if (shmdt(dptr) == -1)
        {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }
    }
}
int main()
{
    int count=0;
    createSharedMemory();
    while(1)
    {
        printf("%d pass\n", ++count);
        createChildProcess();
        sleep(2);
    }
    return 0;
}