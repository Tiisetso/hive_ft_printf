/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:31 by timurray          #+#    #+#             */
/*   Updated: 2025/06/11 17:07:01 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t func_select(const char key, va_list arg)
{
	ssize_t length;

	length = 0;
	if(key == 'c')
		length = char_handler(va_arg(arg, int));
	else if(key == '%')
		length = char_handler('%');
	else if(key == 's')
		length = str_handler(va_arg(arg, char *));
	else if(key == 'd' || key == 'i')
		length = num_handler(va_arg(arg, int), "0123456789");
	else if(key == 'u')
		length = unum_handler(va_arg(arg, unsigned int), "0123456789");
	else if(key == 'x')
		length = unum_handler(va_arg(arg, unsigned int), "0123456789abcdef");
	else if(key == 'X')
		length = unum_handler(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (key == 'p')
		length = ptr_handler(va_arg(arg, void *), "0123456789abcdef");
	else
		length = char_handler(key);
	return (length);
}

int ft_printf(const char *s, ...)
{
	va_list	args;
	ssize_t length;

	length = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while(*s)
	{
		if (*s == '%' && *(s + 1))
			length += func_select(*++s, args);
		else
			length += write(1, s, 1);
		s++;
	}
	va_end(args);
	return((int)length);
}

/* 
TODO What if write fails?
TODO What about multiple %%% and percent at the end?
TODO ft_
TODO Run more tests
TODO pass va_list by reference
TODO norminette

*/
