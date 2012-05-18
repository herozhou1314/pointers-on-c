/* 
Pointers on C - Chapter 4 - Exercise 2 
naive_prime.c - naive method for printing primes from 1-100 

author: nicolas steven miller <nicolasmiller@gmail.com>
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
	int i, j;
	int prime;
	for(i = 1; i < 100; i++) {
		prime = 1;
		for(j = 2; j < i; j++) {
			if(i % j == 0) 
				prime = 0;
		}
		if(prime)
			printf("%d\n", i);
	}
	
	return 1;
}
