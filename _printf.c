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
	if (*format == NULL)
		exit(98);
	va_start(the_argmnts, format);
	while (*format)
	{
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
				case 'd':
					num_of_char += fprintf(stdout, "%d", va_arg(the_argmnts, double));
					break;
				case 'i':
					num_of_char += fprintf(stdout, "%d", va_arg(the_argmnts, int));
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
