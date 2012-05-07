/* 
Pointers on Pointers on C - Chapter 4 - Exercise 3 
triangle.c - determine type of triangle for integer side length inputs 

author: nicolas steven miller <nicolasmiller@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>

int main(char *argv[], int argc)
{
	char triangle[3];
	printf("Enter 3 side lengths separate by spaces: ");
	if(scanf("%d %d %d", 
		&triangle[0], 
		&triangle[1], 
		&triangle[2]) != 3) {
		printf("Invalid input.\n");
		exit(1);
	}

	if(triangle[0] < 1 ||
		triangle[1] < 1 ||
		triangle[2] < 1) {
		printf("Bad side length.\n");
		exit(1);
	}

	if(triangle[0] == triangle[1] &&
		triangle[0] == triangle[2]) {
		printf("equalateral\n");
	}
	else if(triangle[0] == triangle[1] ||
		triangle[0] == triangle[2] ||
		triangle[1] == triangle[2]) {
		printf("isosceles\n");
	}
	else {
		printf("scalene\n");
	}

	return 1;
}
