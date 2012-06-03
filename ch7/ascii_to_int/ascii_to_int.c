/*
Pointers on c - ch7, ex3
ascii_to_int.c - ascii_to_int function and test cases

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int ascii_to_int(char *string)
{
	int return_val = 0;
	while(*string != '\0') {
		if(!(*string >= '0' && *string <= '9'))
			return 0;
		return_val *= 10;
		return_val += *string - '0';
		string++;
	}
	return return_val;
}

int main(int argc, char* argv[])
{
	printf("%d\n", ascii_to_int("12345")); /* 12345 */
	printf("%d\n", ascii_to_int("012345")); /* 12345 */
	printf("%d\n", ascii_to_int("64512")); /* 64512 */
	printf("%d\n", ascii_to_int("000")); /* 0 */
	printf("%d\n", ascii_to_int("fqp000")); /* 0 */
	printf("%d\n", ascii_to_int("4128733x")); /* 0 */
}
