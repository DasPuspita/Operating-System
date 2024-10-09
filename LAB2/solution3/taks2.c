#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_INTEGERS 5

void* print_n(void* arg) {
	long thread_id = (long)arg;
    
	for (int x = 1; x <= NUM_INTEGERS; x++) {
    	printf("Thread %ld prints %d\n", thread_id, thread_id * NUM_INTEGERS + x);
	}
    
	return NULL;
}

int main() {
	pthread_t threads[NUM_THREADS];
	int rct;
    
	
	for (long th = 0; th < NUM_THREADS; th++) {
    	rct = pthread_create(&threads[th], NULL, print_n, (void *)th);
    	if (rct) {
        	printf("ERROR; return code from pthread_create() is %d\n", rct);
        	return -1;
    	}

    	
    	pthread_join(threads[th], NULL);
	}

	return 0;
}


