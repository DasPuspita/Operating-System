#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

int main(int arg, char *arg1[]) {
	if (arg < 2) {
    	printf("Usage: %s <a>\n", arg1[0]);
    	return 1;
	}

	
	FILE *file = fopen(arg1[1], "a+");
	if (file == NULL) {
    	perror("Error opening file");
    	return 1;
	}

	char buf[BUFFER_SIZE];
	printf("Enter strings to write to the file. Enter '-1' to stop.\n");
	while (1) {
    	
    	printf("Input a string: ");
    	fgets(buf, BUFFER_SIZE, stdin);

    	
    	if (buf[0] == '-' && buf[1] == '1' && (buf[2] == '\n' || buf[2] == '\r' || buf[2] == '\0')) {
        	break;
    	}

    	
    	fputs(buf, file);
	}

	
	fclose(file);
	printf("File written successfully.\n");

	return 0;
}

