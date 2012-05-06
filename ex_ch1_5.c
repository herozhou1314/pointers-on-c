/*
Pointers on C - Chapter 1 - Exercise 4
ex_ch1_5.c - Modify rearrange function in chapter example for non-increasing order inputs 

author: nicolas steven miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_COLS 20
#define MAX_INPUT_LENGTH 1000

int read_column_numbers(int columns[], int max);
void rearrange(char* output, char const *input, int n_columns, int columns[]);
void selection_sort(int columns[], int n_columns); 
void print_columns(int const columns[], int n_columns);

int main(void)
{
	int n_columns;
	int columns[MAX_COLS];
	char input[MAX_INPUT_LENGTH];
	char output[MAX_INPUT_LENGTH];
	
	n_columns = read_column_numbers(columns, MAX_COLS);
		
	printf("unsorted columns: ");
	print_columns(columns, n_columns);
	selection_sort(columns, n_columns); // sort columns array in place
	printf("sorted columns: ");
	print_columns(columns, n_columns);
	
	while(gets(input) != NULL) {
		printf("Original input: %s\n", input);
		rearrange(output, input, n_columns, columns);
		printf("Rearranged line: %s\n", output);
	}

	return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch;

	while(num < max && scanf("%d", &columns[num]) == 1
		&& columns[num] >= 0)
		num += 1;

	if(num % 2 != 00) {
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	while((ch = getchar()) != EOF && ch != '\n');

	return num;
}

int find_min_in_range(int start, int n_columns, int columns[])
{
	int current_min = INT_MAX;
	int min_index;
	int i;
	for(i = start; i < n_columns; i++) {
		if(columns[i] < current_min) {
			current_min = columns[i];
			min_index = i;
		}
	}
	return min_index;
}

void selection_sort(int columns[], int n_columns)
{
	int min_index;
	int temp;
	int i;

	for(i = 0; i < n_columns; i++) {
		min_index = find_min_in_range(i, n_columns, columns);
		temp = columns[i];
		columns[i] = columns[min_index];
		columns[min_index] = temp;
	}
}

void print_columns(int const columns[], int n_columns)
{
	int i;
	for(i = 0; i < n_columns; i++)
		printf("%d ", columns[i]);

	printf("\n");
}

void rearrange(char* output, char const *input, int n_columns, 
	int columns[])
{
	int col;
	int output_col;
	int len;
	
	len = strlen(input);
	output_col = 0;

	for(col = 0; col < n_columns; col += 2) {
		int  nchars = columns[col + 1] - columns[col] + 1;

		if(columns[col] >= len ||
			output_col == MAX_INPUT_LENGTH - 1)
			break;

		if(output_col + nchars > MAX_INPUT_LENGTH - 1)
			nchars = MAX_INPUT_LENGTH - output_col - 1;

		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';
}

