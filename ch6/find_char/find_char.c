/*
Pointers on c - ch6, ex1
find_char.c - find_char function as sepcified in text and main test function

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int matches(char const *target, char const *chars)
{
	while(*chars != '\0') {
		if(*target == *chars) 
			return 1;
		chars++;
	}
	return 0;
}

const char *find_char(char const *source, char const *chars)
{
	if(source == NULL || chars == NULL
		|| *source == '\0' ||
		*chars == '\0')
		return NULL; 
	
	while(*source != '\0') {
		if(matches(source, chars))
			return source;
		source++;
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	char *source1  = "ABCDEFG";
	char *source2 = "QQQXQQQPRRRT";
	char *chars1 = "XYZ";
	char *chars2 = "JURY";
	char *chars3 = "QQQQ";
	char *chars4 = "XRCQEF";
	char *chars5 = "EERP";
	char *empty = "";

	printf("%d\n", find_char(NULL, chars1) == NULL); /* NULL */
	printf("%d\n", find_char(source1, NULL) == NULL); /* NULL */
	printf("%d\n", find_char(NULL, NULL) == NULL); /* NULL */
	printf("%d\n", find_char(empty, chars1) == NULL); /* NULL */
	printf("%d\n", find_char(source1, empty) == NULL); /* NULL */

	printf("%d\n", find_char(source1, chars1) == NULL); /* NULL */
	printf("%d\n", find_char(source1, chars2) == NULL); /* NULL */
	printf("%d\n", find_char(source1, chars3) == NULL); /* NULL */
	printf("%d\n", *find_char(source1, chars4) == 'C'); /* C */
	printf("%d\n", *find_char(source2, chars5) == 'P'); /* C */
	
	return 1;
}
