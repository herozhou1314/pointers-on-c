/*
Pointers on c - ch7, ex5
basic_printf.c - basic_printf function and test 

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <stdarg.h>


/* allowed to assume these print functions exist */
void print_integer(int i) {
	printf("%d", i);
}

void print_float(float f) {
	printf("%f", f);
}

void basic_printf(char *format, ...)
{
	va_list args;
	va_start(args, format);
	while(*format != '\0') {
		if(*format == '%') {
			format++;
			if(*format == 'd') {
				print_integer(va_arg(args, int));
			}
			else if(*format == 'f') {
				print_float(va_arg(args, double));
			}
			else if(*format == 's') {
				char *string = va_arg(args, char *);
				while(*string != '\0') {
					putchar(*string);
					string++;
				}
			}
			else if(*format == 'c') {
				putchar(va_arg(args, int));
			}
		}
		else {
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}

int main(int argc, char* argv[])
{
	basic_printf("awesome string without any format codes\n");
	basic_printf("%f %d %d %c\n", 3.1415, 72, 42, 'a');
	basic_printf("%s %d %d %s\n", "here's a string to insert", 69, 69, "here's another string to insert");
	return 1;
}
