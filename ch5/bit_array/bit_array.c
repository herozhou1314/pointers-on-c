/*
Pointers on c - ch5, ex4
bit_array.c - bit_array functions and main test function
bit_numbers start from zero

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"

#define ARRAY_SIZE 32

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
	return bit_array[array_index(bit_number)] &= mask;
}

int main(int argc, char* argv[])
{
	char bit_array[ARRAY_SIZE];
	int i;
	
	// clear all bits to start
	for(i = 0; i < ARRAY_SIZE; i++) {
		clear_bit(bit_array, i);
	}

	set_bit(bit_array, 24);
	if(test_bit(bit_array, 24))
		printf("bit 24 was set\n");	
	else {
		printf("failure\n");	
		exit(-1);
	}
	
	// verify no other bits were set
	for(i = 0; i < ARRAY_SIZE; i++) {
		if(i == 24)
			continue;
		if(test_bit(bit_array, i)) {
			printf("another bit was set; failure\n");
			exit(-1);
		}
	}
	
	clear_bit(bit_array, 24);
	for(i = 0; i < ARRAY_SIZE; i++) {
		if(test_bit(bit_array, i)) {
			printf("all bits should be zero; failure\n");
			exit(-1);
		}
	}

	assign_bit(bit_array, 13, 1);
	if(test_bit(bit_array, 13))
		printf("bit 13 was set\n");	
	else {
		printf("failure\n");	
		exit(-1);
	}
	
	// verify no other bits were set
	for(i = 0; i < ARRAY_SIZE; i++) {
		if(i == 13)
			continue;
		if(test_bit(bit_array, i)) {
			printf("another bit was set; failure\n");
			exit(-1);
		}
	}

	assign_bit(bit_array, 13, 0);
	for(i = 0; i < ARRAY_SIZE; i++) {
		if(test_bit(bit_array, i)) {
			printf("all bits should be zero; failure\n");
			exit(-1);
		}
	}
	return 1;
}
