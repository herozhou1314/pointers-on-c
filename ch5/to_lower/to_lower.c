/*
Pointers on c - ch5, ex1
to_lower.c - read chars and prints them out converting upper to lower

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int main(char *argv[], int argc)
{
	int ch;
	while((ch = getchar()) && ch != EOF) {
		if(ch >= 'A' && ch <= 'Z')
			putchar(ch + 32);
		else
			putchar(ch);
	}
	return 1;
}
