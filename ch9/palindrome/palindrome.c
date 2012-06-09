/*
Pointers on c - ch9, ex10
palindrome.c - determine if string is palindrome 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int palindrome(char *str)
{
	char *end = str;
	while(*end != '\0')
		end++;
	end--;

	while(str < end) {
		if(*str != *end)
			return 0;
		str++;
		end--;
	}

	return 1;
}

int main(int argc, char* argv[])
{
	char str1[] = "abcdefgabcdefg111";
	char str2[] = "abcdefggfedcba";
	char str3[] = "abcdefgfedcba";
	char str4[] = "11111111";
	char str5[] = "11111112";
	char str6[] = "31111112";
	char str7[] = "3";
	char str8[] = "";

	printf("%d\n", palindrome(str1));
	printf("%d\n", palindrome(str2));
	printf("%d\n", palindrome(str3));
	printf("%d\n", palindrome(str4));
	printf("%d\n", palindrome(str5));
	printf("%d\n", palindrome(str6));
	printf("%d\n", palindrome(str7));
	printf("%d\n", palindrome(str8));

	return 1;
}
