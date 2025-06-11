/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:47:01 by timurray          #+#    #+#             */
/*   Updated: 2025/06/11 17:07:35 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t str_len(char *s)
{
	ssize_t	length;

	length = 0;
	while(*s++)
		length += 1;
	return (length);
}

ssize_t	ft_putchar_fd(char c, int fd)
{
	ssize_t res;

	res = (write(fd, &c, 1));
	if (res == -1)
		return (-1);
	return (1);
}

ssize_t	ft_putstr_fd(char *s, int fd)
{
	ssize_t count;
	ssize_t res;

	count = 0;
	res = 0;
	while (*s)
	{
		res = ft_putchar_fd(*s, fd);
		if(res == -1)
			return (-1);
		count += res;
		s++;
	}
	return (count);
}

ssize_t char_handler(int c)
{
	return (ft_putchar_fd(c, 1));
}

ssize_t str_handler(char *s)
{
	if(!s)
		return (ft_putstr_fd("(null)", 1));
	else
		return (ft_putstr_fd(s, 1));
}

ssize_t num_handler(long num, char *s)
{
	ssize_t count;
	int base_length;

	base_length = str_len(s);
	if(num < 0)
	{
		// write(1, "-", 1);
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
		return (num_handler(-num, s) + 1);
	}
	else if (num < base_length)
	{
		if (ft_putchar_fd(s[num], 1) == -1)
			return (-1);
		// return (write(1, &s[num], 1));
		return (1);
	}
	else
	{
		count = num_handler(num / base_length, s);
		return (num_handler(num % base_length, s) + count);
	}	
}

ssize_t unum_handler(unsigned long long num, char *s)
{
	ssize_t count;
	unsigned long base_length;

	base_length = (unsigned long)str_len(s);
	if (num < base_length)
	{
		if (ft_putchar_fd(s[num], 1) == -1)
			return (-1);
		// return (write(1, &s[num], 1));
		return (1);
	}
	else
	{
		count = unum_handler(num / base_length, s);
		return (unum_handler(num % base_length, s) + count);
	}	
}

ssize_t ptr_handler(void *ptr, char *s)
{
	ssize_t count;
	unsigned long base;

	count = 0;
	if(!ptr)
		return (ft_putstr_fd("(nil)", 1));
	else
	{
		count += str_handler("0x");
		base = (unsigned long)str_len(s);
		count += unum_handler((uintptr_t)ptr, s);
		return (count);
	}
}
