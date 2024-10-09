#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* thread(void* arg1) {
	long thread_id = (long)arg1;
    
	printf("thread-%ld running\n", thread_id);
	sleep(1); 
	printf("thread-%ld closed\n", thread_id);
    
	return NULL;
}

int main() {
	pthread_t threads[5];
	int rc;
	long th;
    
	for (th = 1; th <= 5; th++) {
    	printf("In main: creating thread %ld\n", t);
    	rc = pthread_create(&threads[th-1], NULL, thread, (void *)th);
   	 
    	if (rc) {
        	printf("ERROR; return code from pthread_create() is %d\n", rc);
        	return -1;
    	}

    
    	pthread_join(threads[th-1], NULL);
	}
    
	return 0;
}

