/* 
Pointers on C - Chapter 4 - Exercise 5 
print_dup_lines.c - prints one copy of each set of identical input lines
assuming max line length of 128 

author: nicolas steven miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 128

int main(char *argv[], int argc)
{
	char past[MAX_LINE_LENGTH];
	char input[MAX_LINE_LENGTH];
	int should_print = 0;
	while(gets(input) != NULL) {
		if(strcmp(input, past) == 0)
			should_print = 1;
		else if(should_print) {
			printf("%s\n", past);
			should_print = 0;
		}
		strcpy(past, input);
	}
	
	return 1;
}
