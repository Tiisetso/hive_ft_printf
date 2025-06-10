/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:04:04 by timurray          #+#    #+#             */
/*   Updated: 2025/06/10 15:58:51 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //TODO Remove
#include <limits.h>

int main (void)
{
	int i = 12;
	char c = 'c';
	int h = -123456789;
	char *s = "hello world";
	unsigned int u = INT_MAX;
	int p = 0;



	int count = ft_printf("\nc: %c, i: %i, s: %s, h: %x, p: %p, u: %u, X: %X, p: %p", c, i, s, h, p, u, h, 0);
	printf("\nc: %c, i: %i, s: %s, h: %x, p: %p, u: %u, X: %X, %p: ", c, i, s, h, p, u, h, 0);
	printf("\n\n------------------------\nchar count: %i\n", count);
	return (0);
}