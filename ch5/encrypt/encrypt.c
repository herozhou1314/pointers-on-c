/*
Pointers on c - ch5, ex2
encrypt.c - read chars and prints them out encrypting alphas
per algorithm given in ex 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int encrypt(int ch)
{
	if(ch >= 'a' && ch <= 'z')
		return 'a' + ((ch - 'a') + 13) % 26;
	else 
		return 'A' + ((ch - 'A') + 13) % 26;
}

int main(char *argv[], int argc)
{
	int ch;
	while((ch = getchar()) && ch != EOF) {
		if((ch >= 'A' && ch <= 'Z') ||
		   (ch >= 'a' && ch <= 'z'))
			putchar(encrypt(ch));
		else
			putchar(ch);
	}
	return 1;
}
