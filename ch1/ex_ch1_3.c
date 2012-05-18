/*
Pointers on C - Chapter 1 - Exercise 3
ex_ch1_3.c - Input line echoer w/ checksum (ignoring overflow)

author: nicolas steven miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int character = 0;
	char checksum = -1;
	while((character = getchar()) != EOF) {
		checksum += character;
		putchar(character);
		if(character == '\n')
			break;
	}
	printf("%d\n", checksum);
	return 0;
}
