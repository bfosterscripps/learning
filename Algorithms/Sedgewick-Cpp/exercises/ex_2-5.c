#include <stdio.h>
#include <math.h>

double lg(double N){
	
	return log(N) / log(2);
	
}

int main(){
	
	double N, a, b;

	N = a = b = 0;

	int isAGreaterThanB = 1;
	int prevIsGreater = 1;
	int countChanges = 0;	

	while(countChanges < 5){
		N++;
		a = 10 * N * lg(N);
    b = 2 * (N * N);
    printf("is %f > %f?\n", a, b);
		prevIsGreater = isAGreaterThanB;
		isAGreaterThanB = (a > b) ? 1 : 0;
		printf("N: %f\n", N);
		if(!isAGreaterThanB == prevIsGreater)
			countChanges++;
	}

	return 0;
}
