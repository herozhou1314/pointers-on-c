/*
Pointers on c - ch9, ex2
my_strlen.c - my_strlen function and tests 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t my_strlen(const char *s, int size)
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

	printf("%zd\n", my_strlen(str1, 50)); 
	printf("%zd\n", my_strlen(str2, 50)); 
	printf("%zd\n", my_strlen(unterm, 9)); 

	return 1;
}
