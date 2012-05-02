/*
Pointers on C - Chapter 1 - Exercise 2
ex_ch1_2.c

author: nicolas steven miller
*/

#include <stdio.h>

int main(char* argv[], int argc)
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
