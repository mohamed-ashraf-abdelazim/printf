#include "main.h"

/**
 * _printf - a similar function to printf in the standard library
 * @format: the input string parameter pointer
 * Return: num of chars
*/

int _printf(const char *format, ...)
{
	int num_of_char = 0;

	va_list the_argmnts;

	va_start(the_argmnts, format);
	while (*format)
	{
		if (*format == NULL)
		{
			return (-1);
		}
		if (*format != '%')
		{
			putchar(*format);
			num_of_char++;
		}
		else
		{
			switch (*++format)
			{
				case 'c':
					num_of_char += fprintf(stdout, "%c", va_arg(the_argmnts, int));
					break;
				case 's':
					num_of_char += fprintf(stdout, "%s", va_arg(the_argmnts, char *));
					break;
				default:
					putchar('%');
					putchar(*format);
					num_of_char += 2;
					break;
			}
		}
		format++;
	}
	va_end(the_argmnts);
	return (num_of_char);
	}
