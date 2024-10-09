#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int arg, char *arg1[]) {
	int s;

	pid_t pid = fork();
    
	if (pid < 0) {
    	perror("fork failed");
    	exit(EXIT_FAILURE);
	}
	  else if (pid == 0) {
    	
    	char *arg2[] = {"./sort", NULL}; 
    	execvp(arg2[0], arg1);
    	
    	perror("execvp failed for sort");
    	exit(EXIT_FAILURE);
	} else {
    	
    	waitpid(pid, &s, 0); 
   	 
    	if (WIFEXITED(s) && WEXITSTATUS(s) == EXIT_SUCCESS) {
        	
        	execvp("./oddeven", arg1);
        	
        	perror("execvp failed for oddeven");
        	exit(EXIT_FAILURE);
    	} else {
        	
        	perror("child process (sort) failed");
        	exit(EXIT_FAILURE);
    	}
	}
    
	return 0; // This will never be reached
}

