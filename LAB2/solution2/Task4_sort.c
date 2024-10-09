#include <stdio.h>
#include <stdlib.h>

int com(const void *a, const void *b) {
	return (*(int*)b - *(int*)a);
}

int main(int arg, char *arg1[]) {
	if (arg < 2) {
    	fprintf(stderr, "Usage: %s num1 num2...N\n", arg1[0]);
    	return 1;
	}

	int num[arg-1];

	for (int i = 1; i < arg; i++) {
    	num[i-1] = atoi(arg1[i]);
	}

	qsort(num, arg-1, sizeof(int), comp);

	for (int i = 0; i < arg-1; i++) {
    	printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}

