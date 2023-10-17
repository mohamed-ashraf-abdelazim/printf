#include "main.h"

/**
 * _printf - prints stuff o stdout
 * @format: string to be output
 * Return: string formatted
 */

int _print(const char *format, ...)
{
	int val_chars = 0;

	va_list arg_vals;

	va_start (arg_vals, format);
	while(*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			val_chars++;
		}
		else
		{
			switch (++format)
			{
				case '%d':
					val_chars += fprintf(stdout, "%d", va_arg(arg_vals, double));
					break;
				case '%i':
					val_chars += fprintf(stdout, "%i", va_arg(arg_vals, int));
					break;
				default:
					putchar('%');
					putchar(*format);
					val_chars += 2;
					break;
			}
		}
		format++;
	}
	va_end(arg_vals);
	return(val_chars);
}
