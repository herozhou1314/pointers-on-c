/*
Pointers on c - ch9, ex3
my_strcpy.c - my_strcpy with dest_length param to avoid overflow and tests 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

char *my_strcpy(char *dest, const char *source, size_t dest_length)
{
	char *front_of_dest = dest;

	size_t copied = 0;
	while((copied < dest_length) && (*source != '\0')) {
		*dest++ = *source++;
		copied++;
	}
	*dest = '\0';

	return front_of_dest;
}

int main(int argc, char* argv[])
{
	char dest1[9];
	char dest2[9];
	char dest3[9];

	char *src1 = "01234";
	char *src2 = "123456789";
	char *src3 = "123456789abcdf";

	printf("%s\n", my_strcpy(dest1, src1, 9)); 
	printf("%s\n", my_strcpy(dest2, src2, 9)); 
	printf("%s\n", my_strcpy(dest3, src3, 9)); 

	return 1;
}
