/*
Pointers on Pointers on C - Chapter 2 - Exercise 2 
braces_paired.c - verifies that braces in a c source file are paired
(without worrying about braces nested in comments and string or
character literals

author: nicolas steven miller <nicolasmiller@gmail.com>
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
	int braces = 0;
	int ch;
	
	while((ch = getchar()) != EOF) {
		if(ch == '{')
			braces++;
		else if(ch == '}')
			braces--;
	}
	
	if(braces == 0)
		printf("braces balanced\n");
	else
		printf("braces unbalanced\n");
	
	return 1;
}
