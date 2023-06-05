#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define READERS_COUNT 5
#define WRITERS_COUNT 5

sem_t mutex, wrt;
int readcount = 0;

void *reader(void *arg)
{
    int reader_id = *((int *)arg);
    
    while (1)
    {
        // Acquire the mutex to update the readcount
        sem_wait(&mutex);
        readcount++;

        // First reader acquires the wrt semaphore to prevent writers
        if (readcount == 1)
            sem_wait(&wrt);

        // Release the mutex
        sem_post(&mutex);

        // Reader is reading
        printf("Reader %d is reading\n", reader_id);
        sleep(1);

        // Acquire the mutex to update the readcount
        sem_wait(&mutex);
        readcount--;

        // Last reader releases the wrt semaphore to allow writers
        if (readcount == 0)
            sem_post(&wrt);

        // Release the mutex
        sem_post(&mutex);

        // Reader is done reading
        printf("Reader %d finished reading\n", reader_id);
        sleep(1);
    }
}

void *writer(void *arg)
{
    int writer_id = *((int *)arg);
    
    while (1)
    {
        // Writer acquires the wrt semaphore
        sem_wait(&wrt);

        // Writer is writing
        printf("Writer %d is writing\n", writer_id);
        sleep(1);

        // Writer is done writing
        printf("Writer %d finished writing\n", writer_id);
        sleep(1);

        // Writer releases the wrt semaphore
        sem_post(&wrt);
    }
}

int main()
{
    pthread_t rtid[READERS_COUNT], wtid[WRITERS_COUNT];
    int reader_ids[READERS_COUNT];
    int writer_ids[WRITERS_COUNT];
    int i;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for (i = 0; i < READERS_COUNT; i++)
    {
        reader_ids[i] = i + 1;
        pthread_create(&rtid[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (i = 0; i < WRITERS_COUNT; i++)
    {
        writer_ids[i] = i + 1;
        pthread_create(&wtid[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for reader threads to finish
    for (i = 0; i < READERS_COUNT; i++)
        pthread_join(rtid[i], NULL);

    // Wait for writer threads to finish
    for (i = 0; i < WRITERS_COUNT; i++)
        pthread_join(wtid[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
