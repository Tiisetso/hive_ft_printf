/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:47:01 by timurray          #+#    #+#             */
/*   Updated: 2025/06/10 18:07:05 by timurray         ###   ########.fr       */
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

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int count;

	count = 0;
	while (*s)
	{
		count += ft_putchar_fd(*s, fd);
		s++;
	}
	return (count);
}

int char_handler(int c)
{
	return (ft_putchar_fd(c, 1));
}

int str_handler(char *s)
{
	if(!s)
		return (ft_putstr_fd("(null)", 1));
	else
		return (ft_putstr_fd(s, 1));
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

int unum_handler(unsigned long long num, char *s)
{
	int count;
	unsigned long base;

	base = (unsigned long)str_len(s);
	if (num < base)
		return (write(1, &s[num], 1));
	else
	{
		count = unum_handler(num / base, s);
		return (unum_handler(num % base, s) + count);
	}	
}

int ptr_handler(unsigned long ptr, char *s)
{
	int count;
	unsigned long base;

	count = 0;
	if(!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		count += str_handler("0x");
		base = (unsigned long)str_len(s);
		count += unum_handler(ptr, s);
		return (count);
	}
}
