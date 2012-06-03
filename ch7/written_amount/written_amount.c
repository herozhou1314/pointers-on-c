/*
Pointers on c - ch7, ex6
written_amount.c - written_amount function and test

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#define BUFFER_SIZE 1000

const char *digit_to_string(int i) {
	const char *digit_strings[] = {"", "ONE ", "TWO ", "THREE ", "FOUR ", 
				"FIVE ", "SIX ", "SEVEN ", "EIGHT ", "NINE "};
	return digit_strings[i];	
}

const char *teen_to_string(int i) {
	const char *teen_strings[] = {"TEN ", "ELEVEN ", "TWLEVE ", "THIRTEEN ", 
				"FOURTEEN ", "FIFTEEN ", "SIXTEEN ", 
				"SEVENTEEN ", "EIGHTEEN ", "NINETEEN "};
	return teen_strings[i % 10];	
}

const char *tens_to_string(int i) {
	const char *tens_strings[] = {"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", 
				"SIXTY ", "SEVENTY ", "EIGHTY ", "NINETY "};
	return tens_strings[i];	
}

char *copy_str(char *dest, const char *src) {
	while(*src != '\0')
		*dest++ = *src++;
	return dest;
}

void clear_buffer(char *buffer) {
	while(*buffer != '\0')
		*buffer++ = '\0';
}

char *print_hundred(int i, char *buffer) {
	int hundreds = i / 100;
	int tens = (i % 100) / 10;
	int ones = i % 10; 

	if(hundreds > 0) {
		buffer = copy_str(buffer, digit_to_string(hundreds));
		buffer = copy_str(buffer, "HUNDRED ");
	}
	if(tens == 0) {
		buffer = copy_str(buffer, digit_to_string(ones));
	}
	else if(tens == 1) {
		buffer = copy_str(buffer, teen_to_string(ones)); 
	}
	else {
		buffer = copy_str(buffer, tens_to_string(tens));
		buffer = copy_str(buffer, digit_to_string(ones));
	}
}

void written_amount(unsigned int amount, char *buffer)
{

	int billions = amount / 1000000000;
	if(billions > 0) {
		amount %= 1000000000;
		buffer = print_hundred(billions, buffer);
		buffer = copy_str(buffer, "BILLION ");
	}

	int millions =  amount / 1000000;
	if(millions > 0) {
		amount %= 1000000;
		buffer = print_hundred(millions, buffer);
		buffer = copy_str(buffer, "MILLION ");
	}

	int thousands = amount / 1000;
	if(thousands > 0) {
		amount %= 1000;
		buffer = print_hundred(thousands, buffer);
		buffer = copy_str(buffer, "THOUSAND ");
	}
	buffer = print_hundred(amount, buffer);
	*buffer = '\0';
}

int main(int argc, char* argv[])
{
	char buffer[BUFFER_SIZE];
	int val = 65723;

	printf("%d\n", val);
	written_amount(val, buffer);
	printf("%s\n\n", buffer);
	clear_buffer(buffer);
	
	val = 789134;
	printf("%d\n", val);
	written_amount(val, buffer);
	printf("%s\n\n", buffer);
	clear_buffer(buffer);

	val = 9981235;
	printf("%d\n", val);
	written_amount(val, buffer);
	printf("%s\n\n", buffer);
	clear_buffer(buffer);

	val = 12345678;
	printf("%d\n", val);
	written_amount(val, buffer);
	printf("%s\n\n", buffer);
	clear_buffer(buffer);

	val = 123456780;
	printf("%d\n", val);
	written_amount(val, buffer);
	printf("%s\n\n", buffer);
	clear_buffer(buffer);

	val = 2147483647;
	printf("%d\n", val);
	written_amount(val, buffer);
	printf("%s\n\n", buffer);
	clear_buffer(buffer);

	return 1;
}
