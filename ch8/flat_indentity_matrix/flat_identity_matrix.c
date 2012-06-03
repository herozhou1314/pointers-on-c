/*
Pointers on c - ch8, ex4
flat_identity_matrix.c - version of identity matrix for arbirarily sized, flattened, square matrices 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int is_identity_matrix(int *matrix, int dimension)
{
	int row, col;
	for(row = 0; row < dimension; row++) {
		for(col = 0; col < dimension; col++) {
			if(row == col) {
				if(*matrix != 1)
					return 0;
			}
			else {
				if(*matrix != 0)
					return 0;
			}
			matrix++;
		}	
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int matrix1[] = {
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 1
	};	
	int matrix2[] = {
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 4, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 7, 0, 0, 0, 0, 1
	};	
	int matrix3[] = {
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};	
	int matrix4[] = {
		1, 0, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 0, 1
	};	
	int matrix5[] = {
		1, 0, 0, 0, 72,
		0, 1, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 1, 0,
		0, 42, 0, 0, 1
	};	
	int matrix6[] = {
		1, 0, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 0, 1
	};	

	printf("%d\n", is_identity_matrix(matrix1, 10));
	printf("%d\n", is_identity_matrix(matrix2, 10));
	printf("%d\n", is_identity_matrix(matrix3, 10));
	printf("%d\n", is_identity_matrix(matrix4, 5));
	printf("%d\n", is_identity_matrix(matrix5, 5));
	printf("%d\n", is_identity_matrix(matrix6, 5));
	
	return 1;
}
