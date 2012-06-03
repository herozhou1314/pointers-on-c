/*
Pointers on c - ch6, ex4
sieve1.c - basic sieve of eratosthenes 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include "bit_array.h"

#define SIEVE_SIZE 60000000

int main(int argc, char* argv[])
{
	unsigned long long array_size = SIEVE_SIZE / 8;
	char sieve_array[array_size];
	unsigned long long i;
	int step = 2;

	clear_bit(sieve_array, 0);
	clear_bit(sieve_array, 1);

	for(i = 2; i < SIEVE_SIZE; i++) {
		set_bit(sieve_array, i);
	}

	while(step < SIEVE_SIZE) {
		if(!test_bit(sieve_array, step)) {
			step++;
			continue;
		}
		for(i = 2 * step; i < SIEVE_SIZE; i += step) {
			clear_bit(sieve_array, i);
		}
		step++;
	}

	for(i = 0; i < SIEVE_SIZE; i++) {
		int is_prime = test_bit(sieve_array, i);
		if(is_prime)
			printf("%lld\n", i);
	}

	return 1;
}
