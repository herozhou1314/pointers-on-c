/*
Pointers on c - ch9, ex7
my_strrchr.c - rightmost occurance of char

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

char *my_strrchr(char const *str, int ch)
{
	char *match = NULL;
	while(*str++ != '\0')
		if(*str == ch)
			match = str;

	return match;
}

int main(int argc, char* argv[])
{
	char str1[] = "f2f3333333333f34fff";
	char str2[] = "349944848844847";

	printf("%d\n", *my_strrchr(str1, 'f') == 'f');
	printf("%d\n", *my_strrchr(str2, '7') == '7');
	printf("%d\n", my_strrchr(str2, 'f') == NULL);

	return 1;
}
