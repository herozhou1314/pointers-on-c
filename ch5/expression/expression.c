/*
expression.c - expression evaluation ex test

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int a = 10;
 	int b = -25;
	int c = 0;
	int d = 3;
	int e = 20;

	printf("a: %d\n", a); // 10 
	printf("b: %d\n", b); // -25 
	printf("c: %d\n", c); // 0 
	printf("b: %d\n", b); // 3 
	printf("b++: %d\n", b++); // -25, b == -24
	b = -25;
	printf("--a: %d\n", --a); // 9, a == 9
	a++;
	printf("a / 6: %d\n", a / 6); // 1
	printf("a % 6: %d\n", a % 6); // 4
	printf("b % 10: %d\n", b % 10); // -5
	printf("a << 2: %d\n", a << 2); // 40 
	printf("b >> 3: %d\n", b >> 3); // -4 
	printf("a > b: %d\n", a > b); // 1
	printf("b = a: %d\n", b = a); // 10, b == 10 
	b = -25;
	printf("b == a: %d\n", b == a); // 0
	printf("a & b: %d\n", a & b); // 2 
	printf("a ^ b: %d\n", a ^ b); // -19 
	printf("a | b: %d\n", a | b); // -17 
	printf("~b: %d\n", ~b); // 24 
	printf("c && a: %d\n", c && a); // 0 
	printf("c || a: %d\n", c || a); // 1 
	printf("b ? a : c: %d\n", b ? a : c); // 10
	printf("a += 2: %d\n", a += 2); // 12, a == 12
	a = 10;
	printf("a += 2: %d\n", a += 2); // 12, a == 12
	a = 10;
	printf("b &= 20: %d\n", b &= 20); // 4, b == 4
	b = -25;
	printf("b >>= 3: %d\n", b >>= 3); // -4, b == -4
	b = -25;
	printf("a %= 6: %d\n", a %= 6); // 4, a == 4 
	a = 10;
	b = -25;
	d = 3;
	printf("a = b = c = d: %d\n", a = b = c = d); // 3 
	a = 10;
 	b = -25;
	c = 0;
	d = 3;
	printf("e = d + (c = a + b) + c: %d\n", e = d + (c = a + b) + c); // evil. ?? 
	e = 20;
	printf("a + b * 3: %d\n", a + b * 3); // -65 
	printf("b >> a - 4: %d\n", b >> a - 4); // -1 
	printf("a != b != c: %d\n", a != b != c); // 1 
	printf("a == b == c: %d\n", a == b == c); // 1 
	printf("d < a < e: %d\n", d < a < e); // 1 
	printf("e > a > d: %d\n", e > a > d); // 0 
	printf("a - 10 > b + 10: %d\n", a - 10 > b + 10); // 1 
	printf("a & 0x1 == b & 0x1: %d\n", a & 0x1 == b & 0x1); // 0 
	printf("a | b << a & b: %d\n", a | b << a & b); // -25590 
	printf("a > c || ++a > b: %d\n", a > c || ++a > b); // 1, no side fx 
	printf("a > c && ++a > b: %d\n", a > c && ++a > b); // 1, a == 11 
	printf("!~b++: %d\n", !~b); // 0, b == -24
	b = -25;
	printf("b++ & a <= 30: %d\n", b++ & a <= 30); 
	printf("a - b, c += d, e - c: %d\n", a - b, c += d, e - c); 
	c = 0;
	printf("a >>= 3 > 0: %d\n", a >>= 3 > 0); // 5, a == 5 
	printf("a <<= d > 20 ? b && c++ : d--: %d\n", a <<= d > 20 ? b && c++ : d--);
}
