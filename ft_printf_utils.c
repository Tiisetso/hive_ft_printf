/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:47:01 by timurray          #+#    #+#             */
/*   Updated: 2025/06/10 15:57:07 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int str_len(char *s)
{
	int	length;

	length = 0;
	while(*s++)
		length += 1;
	return (length);
}

int char_handler(int c)
{
	return (write(1, &c, 1));
}

int str_handler(char *s)
{
	int count;

	if(!s)
		return (write(1, "(null)", 6));
	count = 0;
	while(*s)
		count += write(1, s++, 1);
	return (count);
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

int unum_handler(unsigned int num, char *s)
{
	int count;
	unsigned int base;

	base = (unsigned int)str_len(s);
	if (num < base)
		return (write(1, &s[num], 1));
	else
	{
		count = unum_handler(num / base, s);
		return (unum_handler(num % base, s) + count);
	}	
}

int lnum_handler(unsigned long num, char *s)
{
	int count;
	unsigned long base;

	base = (unsigned long)str_len(s);
	if (num < base)
		return (write(1, &s[num], 1));
	else
	{
		count = lnum_handler(num / base, s);
		return (lnum_handler(num % base, s) + count);
	}	
}

int ptr_handler(unsigned long ptr, char *s)
{
	int count;
	unsigned long base;

	count = 0;
	// if(ptr == 0)
	// 	return (str_handler("0x0"));
	if(!ptr)
		return (write(1, "(nil)", 6));
	else
	{
		count += str_handler("0x");
		base = (unsigned long)str_len(s);
		count += lnum_handler(ptr, s);
		return (count);
	}
}
