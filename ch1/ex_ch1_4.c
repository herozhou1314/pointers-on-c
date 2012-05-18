/*
Pointers on C - Chapter 1 - Exercise 4
ex_ch1_4.c - Read a series of input lines, compute length of each, print 
only the longest assuming 1000 character max line length (scary...)

author: nicolas steven miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000

int main(int argc, char* argv[])
{
	char buf[MAX_LINE_LENGTH]; 
	char max_buf[MAX_LINE_LENGTH]; 
	int max_length = 0;
	int length = 0;
	int ch = 0;

	while((ch = getchar()) != EOF) {
		buf[length++] = ch;

		if(ch == '\n') {
			buf[length] = '\0';
			if(length > max_length) {
				max_length = length;
				strncpy(max_buf, buf, length + 1);
			}
	
			length = 0;
		}
	}
	printf("%s", max_buf);
	return 0;
}
