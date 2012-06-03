/*
Pointers on c - ch8, ex2
single_tax.c - single_tax function 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>

// yeah floats for money (what the book requires...)
float single_tax(float income)
{
	
	if(income < 0.0) {
		exit(-1);
	}
	else if(income < 23350.0) {
		return 0.15 * income;
	}
	else if(income > 23350.0 && income <= 56550.0) {
		return 3502.5 + (income - 23350) * 0.28;
	}
	else if(income > 56550.0 && income <= 117950.0) {
		return 12798.5 + (income - 56550.0) * 0.31;
	}
	else if(income > 117950.0 && income <= 256500.0) {
		return 31832.5 + (income - 117950.0) * 0.36;
	}
	else {
		return 81710.5 + (income - 256500.0) * 0.396;
	} 
}

int main(int argc, char* argv[])
{
	printf("%f\n", single_tax(10000));
	printf("%f\n", single_tax(20000));
	printf("%f\n", single_tax(110000));
	printf("%f\n", single_tax(210000));
	printf("%f\n", single_tax(310000));
	return 1;
}
