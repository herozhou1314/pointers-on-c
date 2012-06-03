/*
Pointers on c - ch8, ex1
char_values.c - char_values array static initialization 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>


int main(int argc, char* argv[])
{
	/* 3 x 6 x 4 x 5 */
	char char_values[3][6][4][5] = {
		{
		},
		{
			{
			},
			{
				{}
				,
				{0,' ',0,0,0}
			},
			{
				{}
				,
				{}
				,
				{0,0,0,'A',0},
				{0,0,0,0, 'X'}
				
			},
			{
				{}
				,
				{}
				,
				{0,0,0xf3,0,0}
				
			},
			{
				{}
				,
				{}
				,
				{0,0,0,'\n',0}
				
			}
		},
		{
			{}	
			,
			{
				{0,0,0,0,0},
				{0,0,0320,0,0}
				
			},
			{
				{},
				{0,'0',0,0,0},
				{0,0,'\'',0,0},
				{0,'\121',0,0,0}
				
			},
			{
			},
			{
				{},
				{},
				{},
				{0,0,'3',3,0}
				
			}
		}
	};	
	
	printf("%c\n", char_values[1][2][2][3]);
	printf("%c\n", char_values[2][4][3][2]);
	printf("%c\n", char_values[2][4][3][3]);
	printf("%c\n", char_values[2][1][1][2]);
	printf("%c\n", char_values[1][1][1][1]);
	printf("%c\n", char_values[1][4][2][3]);
	printf("%c\n", char_values[2][5][3][4]);
	printf("%c\n", char_values[2][2][2][2]);
	printf("%c\n", char_values[1][3][2][2]);
	printf("%c\n", char_values[2][2][3][1]);
	printf("%c\n", char_values[1][2][3][4]);
	printf("%c\n", char_values[2][2][1][1]);

	return 1;
}
