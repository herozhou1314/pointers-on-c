/* 
Pointers on C - Chapter 4 - Exercise 7 
deblank.c - deblank function, replace consecutive spaces
with a single space and main test function 

author: nicolas steven miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 128

void deblank(char string[])
{
	int len = strlen(string);
	int i, j;
	char *buffer = (char *) malloc(len + 1);
	char last_char = 'q';
	strcpy(buffer, string); 
	for(i = 0, j = 0; i < len; i++) {
		if(buffer[i] == ' ' && last_char == ' ')
			continue;
		string[j] = buffer[i];
		last_char = buffer[i];
		j++;
	}
	string[j] = '\0';
	free(buffer);
}

int main(char *argv[], int argc)
{
	char s1[] = "  foo bar   baz  ";
	char s2[] = "foo     bar       baz    ";
	char s3[] = "f oo";
	deblank(s1);
	deblank(s2);
	deblank(s3);
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	
	return 1;
}
