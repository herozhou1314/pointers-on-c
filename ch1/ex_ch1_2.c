/*
Pointers on C - Chapter 1 - Exercise 2
ex_ch1_2.c - Input line echoer w/ line numbers

author: nicolas steven miller <nicolasmiller.gmail.com>
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int character = 0;
	int line = 0;
	
	while(1) {
		int print_line_num = 1;
		while((character = getchar()) != EOF && character != '\n') {
			if(print_line_num) {
				printf("%d: ", line);
				print_line_num = 0;
			}
			putchar(character);
		}
		if(character == EOF)
			break;
		putchar('\n');
		line++;
	} 
	return 0;
}
