/*
Pointers on c - ch7, ex1
hermite.c - recursive function to compute value of hermite polynomials 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int hermite(int n, int x)
{
	if(n <= 0)
		return 1;
	else if(n == 1)
		return 2 * x;
	else
		return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main(int argc, char* argv[])
{
	printf("%d\n", hermite(3, 2)); /* 40 */
}
