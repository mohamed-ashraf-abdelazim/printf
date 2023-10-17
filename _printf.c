#include "main.h"

/**
 * _printf - a similar function to printf in the standard library
 * @format: the input string parameter pointer
 * Return: num of chars
*/

int _printf(const char *format, ...)
{
	int the_num = 0;

	va_list the_arguments;

	va_start(the_arguments, format);
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			the_num++;
		}
		else if (*format == '\0')
			break;
		switch (*++format)
			{
				case 'c':
					the_num += the_num + fprintf(stdout, "%c", va_arg(the_arguments, int));
					break;
				case 's':
					the_num += fprintf(stdout, "%s", va_arg(the_arguments, char *));
						break;
				default:
					putchar('%');
					putchar(*format);
					the_num = the_num + 2;
					break;
			}
		format++;
	}
va_end(the_arguments);
return(the_num);

}
