/*
Pointers on c - ch9, ex7
my_strnchr.c

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

char *my_strnchr(char const *str, int ch, int which)
{
	char *match = NULL;
	while(*str != '\0') {
		if(*str == ch && which-- > 0)
			match = str;
		str++;
	}

	return match;
}

int main(int argc, char* argv[])
{
	char str1[] = "foo foo2 foo3";

	printf("%s\n", my_strnchr(str1, 'f', 1));
	printf("%s\n", my_strnchr(str1, 'f', 2));
	printf("%s\n", my_strnchr(str1, 'f', 3));
	printf("%s\n", my_strnchr(str1, 'o', 1));
	printf("%s\n", my_strnchr(str1, 'o', 2));
	printf("%s\n", my_strnchr(str1, 'o', 3));
	printf("%s\n", my_strnchr(str1, 'o', 4));
	printf("%s\n", my_strnchr(str1, 'o', 5));
	printf("%s\n", my_strnchr(str1, 'o', 6));
	printf("%s\n", my_strnchr(str1, '3', 6));
	printf("%s\n", my_strnchr(str1, '3', 72));
	printf("%s\n", my_strnchr(str1, '3', 1));

	return 1;
}
