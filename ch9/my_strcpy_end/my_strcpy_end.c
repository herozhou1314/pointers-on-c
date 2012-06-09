/*
Pointers on c - ch9, ex6
my_strcpy_end.c - my_strcpy_end with dest_length param to avoid overflow and tests 
returns pointer to end of string rather than beginning..

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

char *my_strcpy_end(char *dest, const char *source, size_t dest_length)
{
	size_t copied = 0;
	while((copied < dest_length) && (*source != '\0')) {
		*dest++ = *source++;
		copied++;
	}
	*dest = '\0';

	return dest;
}

int main(int argc, char* argv[])
{
	char dest1[9];
	char dest2[9];
	char dest3[9];

	char *src1 = "01234";
	char *src2 = "123456789";
	char *src3 = "123456789abcdf";

	printf("%d\n", *my_strcpy_end(dest1, src1, 9) == '\0');
	printf("%d\n", *my_strcpy_end(dest2, src2, 9) == '\0');
	printf("%d\n", *my_strcpy_end(dest3, src3, 9) == '\0');

	printf("%s\n", dest1); 
	printf("%s\n", dest2); 
	printf("%s\n", dest3); 

	return 1;
}
