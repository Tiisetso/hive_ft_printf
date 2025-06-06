/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:31 by timurray          #+#    #+#             */
/*   Updated: 2025/06/06 16:39:23 by timurray         ###   ########.fr       */
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

int func_select(const char key, va_list arg)
{
	size_t length;

	length = 0;
	if(key == 'c')
		return (char_handler(va_arg(arg, int)));
	if(key == '%')
		return (char_handler('%'));
	if(key == 's')
		return (str_handler(va_arg(arg, char *)));
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
	int count = ft_printf("This is a number: %c and this is a string: %s", 'c',"test string");
	printf("\n\nchar count: %i", count);
	return (0);
}



/* 
TODO • Do not implement the original printf()’s buffer management.
TODO • Your function has to handle the following conversions: cspdiuxX%
TODO • Your implementation will be evaluated against the behavior of the original printf().
TODO • You must use the command ar to create your library.
TODO • The use of the libtool command is strictly forbidden.
TODO • libftprintf.a must be created at the root of your repository.
TODO • You have to implement the following conversions:

 • %c Prints a single character.
 • %s Prints a string (as defined by the common C convention).

TODO • %p The void * pointer argument has to be printed in hexadecimal format.

TODO • %d Prints a decimal (base 10) number.
TODO • %i Prints an integer in base 10.
TODO • %u Prints an unsigned decimal (base 10) number.

TODO • %x Prints a number in hexadecimal (base 16) lowercase format.
TODO • %X Prints a number in hexadecimal (base 16) uppercase format.

TODO • %% Prints a percent sign
TODO What about multiple %%% and percent at the end?
*/
