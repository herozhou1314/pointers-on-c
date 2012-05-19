/*
Pointers on c - ch5, ex3
reverse_bits.c - function reverse_bits (independent of int width) and main test function 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

unsigned int reverse_bits(unsigned int value) 
{
	unsigned int input_value = value;
	unsigned int output = 0;
	unsigned int current_bit;
	unsigned int input_width = 0;
	unsigned int int_width = 0;
	unsigned int output_copy;

	while(input_value != 0) {
		current_bit = 1 & input_value;
		output <<= 1;
		output |= current_bit; 
		input_value >>= 1;
		input_width++;
	}

	output_copy = output;
	while(output_copy != 0) {
		output_copy <<= 1;
		int_width++;
	}
	
	return output <<= int_width - input_width;
}

int main(int argc, char* argv[])
{
	// book test case
	printf("%x\n", 25); // 0x19, 0b11001

	// yields 0x98000000 with 32-bit ints
	printf("%x\n", reverse_bits(25)); 

	printf("%x\n", 1);
	printf("%x\n", reverse_bits(1));	
	return 1;
}
