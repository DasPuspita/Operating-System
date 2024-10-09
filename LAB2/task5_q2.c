#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Parent process ID: %d\n", getpid());

	pid_t c_pid = fork();

	if (c_pid < 0) {
    	
    	perror("Fork failed");
    	return 1;
	} 
	  else if (c_pid == 0) {
    	
    	printf("Child process ID: %d\n", getpid());

    	for (int x = 0; x < 3; x++) {
        	pid_t grandchild_pid = fork();
       	 
        	if (grandchild_pid < 0) {
            	
            	perror("Fork failed");
            	return 1;
        	} 
        	  else if (grandchild_pid == 0) {
            	
            	printf("Grand Child process ID: %d\n", getpid());
            	return 0; 
        	}
        	
        	wait(NULL);
    	}
    	return 0; 
	} 
	  else {
    	
    	wait(NULL);
	}

	return 0;
}

