#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h> 

#define MaxCrops 5 // Maximum crops a Farmer can produce or a ShopOwner can take
#define warehouseSize 5 // Size of the warehouse

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; // Indicating room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; // Initially, all rooms is empty
pthread_mutex_t mutex;

void prWarehouse() { 
    for (int i = 0; i < warehouseSize; i++) {
        printf("%c", warehouse[i]);
    }
    printf("\n"); 
}

void *Farmer(void *far) {
    int f = *((int *)far);
    for (int i = 0; i < MaxCrops; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        
        warehouse[in] = crops[in];
        printf("Farmer %d: Insert crops %c at %d\n", f, warehouse[in], in);
        in = (in + 1) % warehouseSize;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void *ShopOwner(void *sho) {
    int s = *((int *)sho);
    for (int i = 0; i < MaxCrops; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        printf("Shop owner %d: Remove crops %c from %d\n", s, warehouse[out], out);
        warehouse[out] = 'N';
        out = (out + 1) % warehouseSize;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main() {
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize); // When the warehouse is full, the thread will wait
    sem_init(&full, 0, 0); // When the warehouse is empty, the thread will wait

    int a[5] = {1, 2, 3, 4, 5}; // Just used for numbering the Farmer and ShopOwner

    // Create 5 threads for Farmer 5 threads for ShopOwner
    for (int i = 0; i < 5; i++) {
        pthread_create(&Far[i], NULL, Farmer, (void *)&a[i]);
        pthread_create(&Sho[i], NULL, ShopOwner, (void *)&a[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(Far[i], NULL);
        pthread_join(Sho[i], NULL);
    }

    // Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
