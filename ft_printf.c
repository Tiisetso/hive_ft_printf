/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:31 by timurray          #+#    #+#             */
/*   Updated: 2025/06/09 14:44:15 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h> //TODO Remove
#include <unistd.h>

int char_handler(int c)
{
	return (write(1, &c, 1));
}

int str_handler(char *s)
{
	int count;

	count = 0;
	while(*s)
		count += write(1, s++, 1);
	return (count);
}

int str_len(char *s)
{
	size_t	length;

	length = 0;
	while(*s++)
		length += 1;
	return (length);
}

int num_handler(long num, char *s)
{
	int count;
	int base;

	base = str_len(s);
	if(num < 0)
	{
		write(1, "-", 1);
		return (num_handler(-num, s) + 1);
	}
	else if (num < base)
		return (write(1, &s[num], 1));
	else
	{
		count = num_handler(num / base, s);
		return (num_handler(num % base, s) + count);
	}	
}

int ptr_handler(unsigned long ptr)
{
	//TODO 0x
	//check for 0?
	if(ptr == 0)
		str_handler("0x0");
	else
		str_handler("0x");
	return (num_handler(ptr,"0123456789abcdef"));
}

int func_select(const char key, va_list arg)
{
	size_t length;

	length = 0;
	if(key == 'c')
		length = char_handler(va_arg(arg, int));
	else if(key == '%')
		length = char_handler('%');
	else if(key == 's')
		length = str_handler(va_arg(arg, char *));
	else if(key == 'd' || key == 'i' || key == 'u')
		length = num_handler(va_arg(arg, int), "0123456789");
	else if(key == 'x')
		length = num_handler(va_arg(arg, int), "0123456789abcdef");
	else if(key == 'X')
		length = num_handler(va_arg(arg, int), "0123456789ABCDEF");
	else if (key == 'p')
		length = ptr_handler(va_arg(arg, unsigned long));
	else
		length = char_handler(key);
	return (length);
}

int ft_printf(const char *s, ...)
{
	va_list	args;
	size_t length;

	length = 0;	
	va_start(args, s);
	while(*s)
	{
		if (*s == '%')
			length += func_select(*++s, args);
		else
			length += write(1, s, 1);
		s++;
	}
	va_end(args);
	return(length);
}

int main (void)
{
	int i = 12;
	char c = 'c';
	int h = 32;
	char *s = "moika";

	int count = ft_printf("\nchar: %c, int: %i, string: %s, hex: %x, ptr: %p", c, i, s, h, s);
	printf("\nchar: %c, int: %i, string: %s, hex: %x, ptr: %p", c, i, s, h, s);
	printf("\n\n------------------------\nchar count: %i\n", count);
	return (0);
}



/* 
TODO • You must use the command ar to create your library.
TODO • libftprintf.a must be created at the root of your repository.

TODO • %p The void * pointer argument has to be printed in hexadecimal format.

TODO What about multiple %%% and percent at the end?
*/
