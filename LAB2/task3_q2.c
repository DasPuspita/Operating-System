#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int count = 1; 

void check() {
	pid_t pid = fork();
	if (pid == -1) {
    	
    	perror("fork failed");
    	return;
	} else if (pid == 0) {
    	
    	count++;
    	if (getpid() % 2 != 0) {
        	
        	check();
    	}
	} else {
    	
    	wait(NULL); 
	}
}

int main() {
	pid_t a, b, c;

	a = fork();
	if (a == -1) {
    	perror("fork failed");
    	return 1;
	} else if (a == 0) {
    	check();
    	return 0;
	}

	b = fork();
	if (b == -1) {
    	perror("fork failed");
    	return 1;
	} else if (b == 0) {
    	check();
    	return 0;
	}

	c = fork();
	if (c == -1) {
    	perror("fork failed");
    	return 1;
	} else if (c == 0) {
    	check();
    	return 0;
	}

	
	while (wait(NULL) > 0);

	
	printf("Total number of processes created: %d\n", count);

	return 0;
}



