#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *arg1[]) {
	if (arg < 2) {
    	fprintf(stderr, "Usage: %s n1 n2 ... n\n", arg1[0]);
    	return 1;
	}

	for (int x = 1; x < arg; x++) {
    	int n = atoi(arg1[i]);
    	if (n % 2 == 0) {
        	printf("%d is even\n", n);
    	} else {
        	printf("%d is odd\n", n);
    	}
      }

	return 0;
}

