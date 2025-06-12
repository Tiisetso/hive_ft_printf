/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:31 by timurray          #+#    #+#             */
/*   Updated: 2025/06/12 12:55:20 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t func_select(const char key, va_list arg)
{
	ssize_t res;

	res = 0;
	if(key == 'c')
		res = char_handler(va_arg(arg, int));
	else if(key == '%')
		res = char_handler('%');
	else if(key == 's')
		res = str_handler(va_arg(arg, char *));
	else if(key == 'd' || key == 'i')
		res = num_handler(va_arg(arg, int), "0123456789");
	else if(key == 'u')
		res = unum_handler(va_arg(arg, unsigned int), "0123456789");
	else if(key == 'x')
		res = unum_handler(va_arg(arg, unsigned int), "0123456789abcdef");
	else if(key == 'X')
		res = unum_handler(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (key == 'p')
		res = ptr_handler(va_arg(arg, void *), "0123456789abcdef");
	else
		res = char_handler(key);
	return (res);
}

int ft_printf(const char *s, ...)
{
	va_list	args;
	ssize_t length;
	int res;

	length = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while(*s)
	{
		if (*s == '%' && *(s + 1))
		{
			res = func_select(*++s, args);
			if (res == -1)
				return (-1);
			length += res;
		}
		else
		{
			res = ft_putchar_fd(*s, 1);
			if (res == -1)
				return (-1);
			length += res;
		}
		s++;
	}
	va_end(args);
	return((int)length);
}

/* 
TODO shift error check in ft_printf

TODO What about multiple %%% and percent at the end?
TODO Run more tests
TODO pass va_list by reference
TODO norminette

*/
