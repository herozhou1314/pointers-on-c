/*
Pointers on c - ch9, ex11
the_count.c - count occurances of 'the' on standard input assuming:
		-- words separated by one or more whitespace chars
		-- input lines less than 100 lines 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

#define BUFFSIZE 100

int matches(char *str, char *the) {
	while(*the != '\0') {
		if(*str != *the)
			return 0;
		str++;
		the++;
	}

	/* only match if bounded by space or null on right */	
	if(!isspace(*str) || *str == '\0')
		return 0;

	return 1;
}

int the_count(char *str)
{
	int count = 0;
	while(*str != '\0') {
		if(matches(str, "the"))
			count++;

		while(!isspace(*str)) /* skip over rest of word */
			str++;
		while(isspace(*str)) /* skip over space between words */
			str++;
		
	}
	return count;
}

int main(int argc, char* argv[])
{
	char buffer[BUFFSIZE];
	
	while(fgets(buffer, BUFFSIZE, stdin) != NULL) {
		printf("the_count: %d\n", the_count(buffer));
	}	

	return 1;
}
