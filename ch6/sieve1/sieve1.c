/*
Pointers on c - ch6, ex4
sieve1.c - basic sieve of eratosthenes 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#define SIEVE_SIZE 8250000

int main(int argc, char* argv[])
{
	char sieve_array[SIEVE_SIZE];
	unsigned long long i;
	int step = 2;

	sieve_array[0] = 0;
	sieve_array[1] = 0;

	for(i = 2; i < SIEVE_SIZE; i++) {
		sieve_array[i] = 1;
	}

	while(step < SIEVE_SIZE) {
		if(!sieve_array[step]) {
			step++;
			continue;
		}
		for(i = 2 * step; i < SIEVE_SIZE; i += step) {
			sieve_array[i] = 0;	
		}
		step++;
	}

	for(i = 0; i < SIEVE_SIZE; i++) {
		if(sieve_array[i])
			printf("%lld: %d\n", i, sieve_array[i]);
	}
	return 1;
}
