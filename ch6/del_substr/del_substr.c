/*
Pointers on c - ch6, ex2
del_substr.c - del_substr function and test cases as specified in text 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int matches_at_position(char *position, char const *substr)
{
	while(*position != '\0' && *substr != '\0') {
		if(*position != *substr)
			return 0;
		position++;
		substr++;
	}

	/* got to the end of the substr and everything matched */
	return *substr == '\0'; 
}

/* not allowed to use std library funcs */
int my_naive_strlen(char const *str) {
	unsigned int length = 0;
	while(*str != '\0') {
		length++;
		str++;
	}
	return length;
}

char *substr_pos(char *str, char const *substr)
{
	while(*str != '\0') {
		if(matches_at_position(str, substr))
			return str;
		str++;
	}
	
	return NULL;
}

int del_substr(char *str, char const *substr)
{
	char *substr_start = substr_pos(str, substr);
	if(substr_start == NULL)
		return 0;
	char *after_substr = substr_start + my_naive_strlen(substr);

	while(*after_substr != '\0') {
		*substr_start =  *after_substr;
		substr_start++;
		after_substr++;
	}
	*substr_start = '\0';
	
	return 1;
}

int main(int argc, char* argv[])
{
	char str1[] = "ABCDEFG";
	char str2[] = "XXXXFOOBARXXXXXX";
	char str3[] = "XXXXFOOBARXXXXXX";
	char str4[] = "XXXXFOOBARXXXXXX";
	char substr1[] = "FGH";
	char substr2[] = "CDF";
	char substr3[] = "XABC";
	char substr4[] = "CDE";
	char substr5[] = "FOOBAR";
	char substr6[] = "FOO";
	char substr7[] = "BAR";
	

	printf("%d\n", my_naive_strlen(str1) == 7);
	printf("%d\n", my_naive_strlen(substr1) == 3);
	printf("%d\n", my_naive_strlen(substr2) == 3);
	printf("%d\n", my_naive_strlen(substr3) == 4);
	printf("%d\n", my_naive_strlen(substr4) == 3);

	printf("%d\n", del_substr(str1, substr1) == 0);
	printf("%s\n", str1); /* should be unchanged */
	printf("%d\n", del_substr(str1, substr2) == 0);
	printf("%s\n", str1); /* should be unchanged */
	printf("%d\n", del_substr(str1, substr3) == 0);
	printf("%s\n", str1); /* should be unchanged */
	printf("%d\n", del_substr(str1, substr4) == 1);
	printf("%s\n", str1); /* should be ABFG */
	printf("%d\n", del_substr(str2, substr5) == 1);
	printf("%s\n", str2); /* should be XXXXXXXXXX */
	printf("%d\n", del_substr(str3, substr6) == 1);
	printf("%s\n", str3); /* should be XXXXBARXXXXXX */
	printf("%d\n", del_substr(str4, substr7) == 1);
	printf("%s\n", str4); /* should be XXXXFOOXXXXXX */

	return 1;
}
