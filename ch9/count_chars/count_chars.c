/*
Pointers on c - ch9, ex9
count_chars.c - count chars in str that match any of set of chars

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int count_chars(char const *str, char const *chars)
{
	int count = 0;
	char const *chars_ptr = chars;
	while(*str != '\0') {
		while(*chars_ptr != '\0') {
			if(*str == *chars_ptr) {
				count++;
				break;
			}
			chars_ptr++;
		}
		chars_ptr = chars;
		str++;
	}
	
	return count;
}
int main(int argc, char* argv[])
{
	char str1[] = "abcdefgabcdefg111";
	char chars1[] = "abcdef";
	char chars2[] = "abc";
	char chars3[] = "1";
	char chars4[] = "2";
	char chars5[] = "";

	printf("%d\n", count_chars(str1, chars1) == 12);
	printf("%d\n", count_chars(str1, chars2) == 6);
	printf("%d\n", count_chars(str1, chars3) == 3);
	printf("%d\n", count_chars(str1, chars4) == 0);
	printf("%d\n", count_chars(str1, chars5) == 0);

	printf("%d\n", count_chars(str1, chars1));
	printf("%d\n", count_chars(str1, chars2));
	printf("%d\n", count_chars(str1, chars3));
	printf("%d\n", count_chars(str1, chars4));
	printf("%d\n", count_chars(str1, chars5));

	return 1;
}
