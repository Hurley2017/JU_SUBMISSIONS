//using semaphores write p1, p2, p3 process printing A, B, C in process synchronisation

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

sem_t s1,s2,s3;

void *p1()
{
    while(1)
    {
        sem_wait(&s1);
        printf("A");
        sem_post(&s2);
    }    
}

void *p2()
{
    while(1)
    {
        sem_wait(&s2);
        sem_post(&s1);
        sem_wait(&s2);        
        printf("B");
        sem_post(&s3);
        sem_wait(&s2);
        sem_post(&s3);
        sem_wait(&s2);
        sem_post(&s1);
    }    
}

void *p3()
{
    while(1)
    {
        sem_wait(&s3);
        printf("C");
        sem_post(&s2);
    }    
}

int main()
{
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    sem_init(&s3,0,0);
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,p1,NULL);
    pthread_create(&t2,NULL,p2,NULL);
    pthread_create(&t3,NULL,p3,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);
    return 0;
}