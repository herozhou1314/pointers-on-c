/* 
Pointers on C - Chapter 2 - Exercise 1 
main.c - main test function for increment and negate functions

author: nicolas steven miller <nicolasmiller@gmail.com>
*/
#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main(int argc, char* argv[])
{
	printf("increment(10) : %d\n", increment(10));
	printf("increment(0) : %d\n", increment(0));
	printf("increment(-10) : %d\n", increment(-10));
	printf("negate(10) : %d\n", negate(10));
	printf("negate(0) : %d\n", negate(0));
	printf("negate(-10) : %d\n", negate(-10));
	return 1;
}

