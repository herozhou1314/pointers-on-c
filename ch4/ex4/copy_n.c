/* 
Pointers on C - Chapter 4 - Exercise 4 
copy_n.c - copy_n function and main test function 

author: nicolas steven miller <nicolasmiller@gmail.com>
*/
#include <stdio.h>
#include <string.h>

void copy_n(char dst[], char src[], int n) {
	int len = strlen(src);
	int i;
	for(i = 0; i < n; i++) {
		if(i < len)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}
}

int main(int argc, char* argv[])
{
	char src[] = "foobar";
	char dst[32];
	copy_n(dst, src, 2); // n < len; not nul terminated
	dst[2] = '\0';
	printf("%s\n", dst);
	copy_n(dst, src, 4); // n < len; not nul terminated
	dst[4] = '\0';
	printf("%s\n", dst);
	copy_n(dst, src, 6); // n == len; not nul terminated
	dst[6] = '\0';
	printf("%s\n", dst);
	copy_n(dst, src, 16); // n >= len; nul terminated
	printf("%s\n", dst);
	return 1;
}
