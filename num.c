/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:34:39 by timurray          #+#    #+#             */
/*   Updated: 2025/06/09 13:39:48 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int main (void)
{
	int count;

	count = num_handler(-32, "0123456789abcdef");

	char *s = "hey";
	unsigned long i = (unsigned long)s;
	printf("\nthe address is:%p\n", s);
	// printf("\n as an int: %lu", i);

	count = num_handler(i, "0123456789abcdef");

	printf("\nwritten: %i", count);
	return (1);
}