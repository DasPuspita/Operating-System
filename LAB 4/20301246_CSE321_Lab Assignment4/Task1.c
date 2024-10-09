#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10 // producers and consumers can produce and consume up to MAX
#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */

void *consumer(void *id);
void *producer(void *id);

char buffer[BUFLEN];
char source[BUFLEN]; // from this array producer will store its production into buffer
int pCount = 0;
int cCount = 0;
int buflen;
// initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

int main() {
    int i;
    pthread_t threads[NUMTHREAD];
    strcpy(source, "abcdef");
    buflen = strlen(source);
    /*create 2 threads*/
    /* create one consumer and one producer */
    /* define the properties of multi threads for both threads  */

    pthread_create(&threads[0], NULL, producer, (void *)&thread_id[0]);
    pthread_create(&threads[1], NULL, consumer, (void *)&thread_id[1]);

    for (i = 0; i < NUMTHREAD; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *producer(void *id) {
    int thread_id = *(int *)id;
    while (1) {
        pthread_mutex_lock(&count_mutex);
        while ((pCount - cCount) == BUFLEN) {
           
            pthread_cond_wait(&full, &count_mutex);
        }
        if (pCount < MAX) {
            int i = pCount % buflen;
            buffer[i] = source[i];
            printf("%d produced  %c  by Thread  %d\n", pCount, buffer[i], thread_id);
            pCount++;
            pthread_cond_signal(&nonEmpty); 
        }
        else {
            pthread_mutex_unlock(&count_mutex);
            break; 
        }
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}

void *consumer(void *id) {
    int thread_id = *(int *)id;
    while (1) {
        pthread_mutex_lock(&count_mutex);
        while (pCount == cCount) {
            
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        if (cCount < pCount) {
            int i = cCount % buflen;
            printf("%d consumed  %c  by Thread  %d\n", cCount, buffer[i], thread_id);
            cCount++;
            pthread_cond_signal(&full); 
        }
        else {
            pthread_mutex_unlock(&count_mutex);
            break;
        }
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}
