/*
Pointers on c - ch5, ex5
store_bit_field.c - store_bit_field function and main test function

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int get_mask(unsigned int starting_bit, unsigned int ending_bit) 
{
	int width = (starting_bit - ending_bit) + 1;
	int mask = 1;
	int i;
	for(i = 1; i < width; i++) {
		mask <<= 1;
		mask |= 1;
	}
	
	for(i = 0; i < ending_bit; i++) {
		mask <<= 1;
	}

	return mask;
}

int store_bit_field(int original_value, int value_to_store, 
unsigned int starting_bit, unsigned int ending_bit) {
	int mask = get_mask(starting_bit, ending_bit);
	value_to_store <<= ending_bit;
	value_to_store &= mask;
	original_value &= ~mask;
	return original_value | value_to_store;
}

int main(int argc, char* argv[])
{
	/* test cases given in problem */
	printf("%x\n", store_bit_field(0x0, 0x1, 4, 4)); /* 0x10 */
	printf("%x\n", store_bit_field(0xffff, 0x123, 15, 4)); /* 0x123f */
	printf("%x\n", store_bit_field(0xffff, 0x123, 13, 9)); /* 0xc7ff */
	
	return 1;
}
