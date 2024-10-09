#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid1 = fork(); 

	if (pid1< 0) {
    	
    	fprintf(stderr, "Fork failed\n");
    	return 1;
	}
	  else if (pid1 == 0) {
    	
    	pid_t pid_c = fork(); 

    	if (pid_c < 0) {
        	
        	fprintf(stderr, "Fork failed\n");
        	return 1;
    	} 
    	  else if (pid_c == 0) {
        	
        	printf("I am grandchild\n");
    	} 
    	  else {
        	wait(NULL); 
        	printf("I am child\n");
    	}
      } 
	  else {
    	wait(NULL); 
    	printf("I am parent\n");
	}

	return 0;
}

