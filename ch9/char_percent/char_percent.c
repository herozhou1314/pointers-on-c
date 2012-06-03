/*
Pointers on c - ch9, ex1
char_percent.c - computes distribution of character categories in std input

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	unsigned int num_chars = 0;

	unsigned int num_upper = 0;
	unsigned int num_lower = 0;
	unsigned int num_whitespace = 0;
	unsigned int num_digits = 0;
	unsigned int num_control = 0;
	unsigned int num_punct = 0;
	unsigned int num_non_print = 0;

	int c;
	
	while((c = getchar()) != EOF) {
		if(isupper(c))
			num_upper++;
		else if(islower(c))
			num_lower++;
		else if(isspace(c))
			num_whitespace++;
		else if(isdigit(c))
			num_digits++;
		else if(iscntrl(c))
			num_control++;
		else if(ispunct(c))
			num_punct++;
		else if(!isprint(c))
			num_non_print++;
		num_chars++;
	}

	printf("num chars: %d\n", num_chars);
	printf("upper: %f%%\n", (float) num_upper / (float) num_chars * 100);
	printf("lower: %f%%\n", (float) num_lower / (float) num_chars * 100);
	printf("whitespace: %f%%\n", (float) num_whitespace / (float) num_chars * 100);
	printf("digits: %f%%\n", (float) num_digits / (float) num_chars * 100);
	printf("control: %f%%\n", (float) num_control / (float) num_chars * 100);
	printf("punct: %f%%\n", (float) num_punct / (float) num_chars * 100);
	printf("non-print: %f%%\n", (float) num_non_print / (float) num_chars * 100);

	return 1;
}
