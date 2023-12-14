#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * print_specials - Entry point
 * @d: ...
 * Return: Always 0
 */
int print_specials(char d)
{
	switch (d)
	{
		case 'n':
			d = '\n';
		break;
		case 'a':
			d = '\a';
		break;
		case 'b':
			d = '\b';
		break;
		case 't':
			d = '\t';
		break;
		case 'v':
			d = '\v';
		break;
		case 'r':
			d = '\r';
		break;
		case 'f':
			d = '\f';
		break;
		default:
			write(STDOUT_FILENO, "\\", 1);
		break;
	}
	return (write(STDOUT_FILENO, &d, 1));
}

/**
 * process_directive - Entry point
 * @d: ...
 * @args: ...
 * Return: Always 0
 */
int process_directive(char d, va_list *args)
{
	char int_arg;
	char *str_arg;
	int num_printed = 0;

	switch (d)
	{
		case 'c':
			int_arg = va_arg(*args, int);
			num_printed += write(STDOUT_FILENO, &int_arg, 1);
		break;
		case 's':
			str_arg = va_arg(*args, char *);
			if (str_arg == NULL)
			{
				str_arg = "(null)";
			}
			while (*str_arg != 0)
			{
				num_printed += write(STDOUT_FILENO, str_arg, 1);
				str_arg++;
			}
		break;
		case '%':
			num_printed += write(STDOUT_FILENO, "%", 1);
		break;
		default:
			num_printed += write(STDOUT_FILENO, "%", 1);
			num_printed += write(STDOUT_FILENO, &d, 1);
		break;
	}
	return (num_printed);
}

/**
 * is_flag_char - Entry point
 * @f: ...
 * Return: Always 0
 */
int is_flag_char(char f)
{
	return (f == '+' || f == '-' || f == ' ' || (f >= '0' && f <= '9'));
}

/**
 * get_flags - Entry point
 * @format: ...
 * @i: ..
 * @flags: ..
 * @d: ..
 * Return: Always 0
 */
int get_flags(const char *format, int i,  char *flags, char *d)
{
	int j;
	char f;

	j = 0;
	i++;
	f = format[i];
	if (!is_flag_char(f))
	{
		*d = f;
	}
	else
	{
		while (is_flag_char(f))
		{
			flags[j] = f;
			j++;
			i++;
			f = format[i];
		}
		*d = format[i];
	}
	flags[j] = 0;
	flags[j] = flags[j];
	return (i);
}

/**
 * _printf - Entry point
 * @format: formats
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int num_printed = 0;
	int i;
	char c, d;
	va_list args;
	char flags[10];

	if (format == NULL)
	{
		return (0);
	}

	va_start(args, format);

	i = 0;
	while (format[i] != 0)
	{
		c = format[i];
		if (c == '\\')
		{
			d = format[i + 1];
			i++;
			num_printed += print_specials(d);
		}
		else if (c != '%')
		{
			num_printed += write(STDOUT_FILENO, &c, 1);
		}
		else if (format[i + 1] != 0)
		{
			i = get_flags(format, i, flags, &d);
			num_printed += process_directive(d, &args);
		}
		i++;
	}
	va_end(args);

	return (num_printed);
}
