/*
Pointers on c - ch7, ex4
max_list.c - max_list function and test

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stdarg.h>

int max_list(int dummy, ...)
{
	va_list args;
	int max = 0;
	int value;
	va_start(args, dummy);
	while((value = va_arg(args, int)) > 0) {
		if(value > max)
			max = value;
	}	
	va_end(args);
	return max;
}

int main(int argc, char* argv[])
{
	printf("%d\n", max_list(42, 1, 71, 2, 42, 79, 20, -1)); /* 79 */
	printf("%d\n", max_list(42, 79, 71, 2, 42, 79, 20, -1)); /* 79 */
	printf("%d\n", max_list(42, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1)); /* 11 */
	printf("%d\n", max_list(42, 1, -1)); /* 1 */
	return 1;
}
