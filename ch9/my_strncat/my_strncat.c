/*
Pointers on c - ch9, ex3
my_strcat.c - my_strcat with dest_length param to avoid overflow and tests 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

char *my_strcat(char *dest, const char *source, size_t dest_length)
{
	char *dest_start = dest;
	size_t dest_position = 0;

	while(*dest++ != '\0')
		dest_position++;
	dest--;
	while(dest_position < dest_length && *source != '\0') {
		*dest++ = *source++;
		dest_position++;
	}
	*dest = '\0';

	return dest_start;
}

int main(int argc, char* argv[])
{
	char dest1[10] = "01234";
	char dest2[10] = "foobar";
	char dest3[10] = "";

	char *src1 = "56789";
	char *src2 = "bazquux";
	char *src3 = "Surely you're joking, Mr. Feynman";

	printf("%s\n", my_strcat(dest1, src1, 10)); 
	printf("%s\n", my_strcat(dest2, src2, 10)); 
	printf("%s\n", my_strcat(dest3, src3, 10)); 

	return 1;
}
