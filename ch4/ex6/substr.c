/* 
Pointers on Pointers on C - Chapter 4 - Exercise 6 
substr.c - substr function and main test function 
following req'ts given in ex writeup

author: nicolas steven miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 128

int substr(char dst[], char src[], int start, int len) {
	int src_len = strlen(src);
	int i, j;

	if(start >= src_len ||
	 	start < 0 ||
		len < 0) {
		dst[0] = '\0';
		return 0;
	}
	for(i = start, j = 0; i < start + len; i++, j++) 
		dst[j] = src[i];
	dst[j] = '\0';
	return strlen(dst);
}

int main(char *argv[], int argc)
{
	char *str = "foobarbaz";
	char dest1[16];
	char dest2[16];
	char dest3[16];
	char dest4[16];
	printf("%d\n", substr(dest1, str, 0, 5));
	printf("%d\n", substr(dest2, str, 2, 3));
	printf("%d\n", substr(dest3, str, 7, 2));
	printf("%d\n", substr(dest4, str, 24, 5));
	printf("dest1: %s\n", dest1);
	printf("dest2: %s\n", dest2);
	printf("dest3: %s\n", dest3);
	printf("dest4: %s\n", dest4);
	
	return 1;
}
