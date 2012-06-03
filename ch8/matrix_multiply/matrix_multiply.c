/*
Pointers on c - ch8, ex5
matrix_multiply.c - naive matrix_multiply function, utility funcs and quick test

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int get_val_at_ij(int *matrix, int i, int j, int cols)
{
	return *(matrix + (cols * i + j));
} 

void set_val_at_ij(int *matrix, int i, int j, int cols, int val)
{
	*(matrix + (cols * i + j)) = val;
} 

int c_ij(int *m_a, int *m_b, int i, int j, int y, int z)
{
	int c_ij = 0;
	int k = 0;
	for(; k < y; k++) {
		c_ij += get_val_at_ij(m_a, i, k, y) * get_val_at_ij(m_b, k, j, z);
	}
	
	return c_ij;
}

void matrix_multiply(int *m_a, int *m_b, int *result, int x, int y, int z)
{
	int row;
	int col;
	for(row = 0; row < x; row++) {
		for(col = 0; col < z; col++) {
			set_val_at_ij(result, 
					row, 
					col, 
					z,
					c_ij(m_a, m_b, row, col, y, z));
		}
	}
}

void print_matrix(int *matrix, int rows, int cols) {
	int row;
	int col;
	for(row = 0; row < rows; row++) {
		for(col = 0; col < cols; col++) {
			printf("%d ", get_val_at_ij(matrix, row, col, cols));	
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int x = 3;
	int y = 2;
	int z = 4;
	int i;

	int a[] = {
		2, -6,
		3, 5,
		1, -1 
	};	
	int b[] = {
		4, -2, -4, -5,
		-7, -3, 6, 7
	};	
	int result[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};	

	print_matrix(a, x, y); 
	printf("\n");
	print_matrix(b, y, z); 
	printf("\n");
	print_matrix(result, x, z); 
	printf("\n");

	matrix_multiply(a, b, result, x, y, z);

	print_matrix(result, x, z); 
	printf("\n");
	
	return 1;
}
