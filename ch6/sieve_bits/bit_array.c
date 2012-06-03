/*
Pointers on c - ch5, ex4
bit_array.c - bit_array functions and main test function
bit_numbers start from zero

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"

unsigned int array_index(unsigned int bit_number)
{
	return bit_number / 8;
}

unsigned int bit_index(unsigned int bit_number)
{
	return bit_number % 8;
}

void set_bit(char bit_array[], unsigned bit_number)
{
	unsigned char mask = 1;
	mask <<= bit_index(bit_number);
	bit_array[array_index(bit_number)] |= mask;
}

void clear_bit(char bit_array[], unsigned bit_number)
{
	unsigned char mask = 1;
	mask <<= bit_index(bit_number);
	mask = ~mask;
	bit_array[array_index(bit_number)] &= mask;
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
	if(value) {
		set_bit(bit_array, bit_number);
	}
	else {
		clear_bit(bit_array, bit_number);
	}
}

int test_bit(char bit_array[], unsigned bit_number)
{
	unsigned char mask = 1;
	mask <<= bit_index(bit_number);
	return bit_array[array_index(bit_number)] & mask;
}
