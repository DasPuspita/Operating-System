#include <stdio.h>


typedef struct {
	int v;
} Int;


int perfect(Int num) {
	int sum = 0;
	for (int x = 1; x < num.v; x++) {
    	if (num.v % x == 0) {
        	sum += x;
    	}
    }
	return sum == num.v;
}

int main() {
	Int num1;
	int low, up;

	
	printf("input:\n");
	scanf("%d %d", &low, &up);

	printf("output:\n");
	for (num1.v = low; num1.v <= up; num1.v++) {
    	if (perfect(num1)) {
        	printf("%d\n", num1.v);
    	}
    }
	return 0;
}



