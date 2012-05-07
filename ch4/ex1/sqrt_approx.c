/* 
Pointers on C - Chapter 4 - Exercise 1 
sqrt_approx.c - sqrt approximation

author: nicolas steven miller <nicolasmiller@gmail.com>
*/
#include <stdio.h>
#define DEBUG

float sqrt_approx(float n)
{
	float approx = 1.0f;
	unsigned long int iterations = 0;
	while(1) {
		iterations++;
		float next_approx = (approx + (n / approx)) / 2;
		if(next_approx == approx)
			break;
		approx = next_approx;
	}

#ifdef DEBUG
	printf("num iterations: %d\n", iterations);
#endif 
	
	return approx;
}

int main(char *argv[], int argc)
{
	printf("sqrt_approx(2.0): %f\n", sqrt_approx(2.0f));	
	printf("sqrt_approx(16.0): %f\n", sqrt_approx(16.0f));	
	printf("sqrt_approx(100.0): %f\n", sqrt_approx(100.0f));	
	printf("sqrt_approx(4.2): %f\n", sqrt_approx(4.2f));	
	return 1;
}
