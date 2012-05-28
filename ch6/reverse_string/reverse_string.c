/*
Pointers on c - ch6, ex2
reverse_string.c - reverse_string function and test cases 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

char *last_char(char *string) {
	while(*string != '\0')
		string++;
	return --string;
}

void reverse_string(char *string)
{
	if(string == NULL || *string == '\0')
		return;
	
	char *last_ch_ptr = last_char(string);

	while(string < last_ch_ptr) {
		char temp = *string;
		*string = *last_ch_ptr;
		*last_ch_ptr = temp;
		string++;
		last_ch_ptr--;
	}
}

int main(int argc, char* argv[])
{
	char str1[] = "ABCDEFG";
	char str2[] = "ABCDEF";
	char str3[] = "XXXXXXXXQQQNWNNNNDDJJJEFHHH";
	

	printf("%s\n", str1);
	reverse_string(str1);
	printf("%s\n", str1);

	printf("%s\n", str2);
	reverse_string(str2);
	printf("%s\n", str2);

	printf("%s\n", str3);
	reverse_string(str3);
	printf("%s\n", str3);

	return 1;
}
