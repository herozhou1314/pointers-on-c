/*
Pointers on c - ch7, ex2
gcd.c - gcd function and tests 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int gcd(int m, int n)
{
	if(m < 0 || n < 0)
		return 0;
	if((m % n ) == 0)
		return n;
	else
		return gcd(n, m % n);
}

int main(int argc, char* argv[])
{
	printf("%d\n", gcd(-1, 2)); /* 0 */
	printf("%d\n", gcd(1, -2)); /* 0 */
	printf("%d\n", gcd(64, 2)); /* 2 */
	printf("%d\n", gcd(54, 24)); /* 6 */
}
