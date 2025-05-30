/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:31 by timurray          #+#    #+#             */
/*   Updated: 2025/05/31 17:44:00 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h> //TODO Remove
#include <unistd.h>

int ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	size_t length;

	i = 0;
	length = 0;
	va_start(args, s);
	while(*(s + i))
	{
		if (s[i] == '%')
			i++;
		write(1, (s + i), 1);
		i++;
	}
	va_end(args);
	return(1);
}

int main (void)
{
	ft_printf("This is a number: %d and this is a string: %s");
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
TODO • %c Prints a single character.
TODO • %s Prints a string (as defined by the common C convention).
TODO • %p The void * pointer argument has to be printed in hexadecimal format.
TODO • %d Prints a decimal (base 10) number.
TODO • %i Prints an integer in base 10.
TODO • %u Prints an unsigned decimal (base 10) number.
TODO • %x Prints a number in hexadecimal (base 16) lowercase format.
TODO • %X Prints a number in hexadecimal (base 16) uppercase format.
TODO • %% Prints a percent sign 
*/
