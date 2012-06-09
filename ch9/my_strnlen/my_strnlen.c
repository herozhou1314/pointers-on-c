/*
Pointers on c - ch9, ex2
my_strnlen.c - my_strnlen function and tests 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t my_strnlen(const char *s, int size)
{
	unsigned int length = 0;
	while(length < size && *s != '\0') {
		length++;
		s++;
	}
	
	return length;
}

int main(int argc, char* argv[])
{
	char *str1 = "here's a string sdfjkl";
	char *str2 = "123456789";
	char unterm[9] = "123456789";

	printf("%zd\n", my_strnlen(str1, 50)); 
	printf("%zd\n", my_strnlen(str2, 50)); 
	printf("%zd\n", my_strnlen(unterm, 9)); 

	return 1;
}
