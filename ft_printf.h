/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:09 by timurray          #+#    #+#             */
/*   Updated: 2025/06/10 18:07:11 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int char_handler(int c);
int str_handler(char *s);
int str_len(char *s);
int num_handler(long num, char *s);
int unum_handler(unsigned long long num, char *s);
int ptr_handler(unsigned long ptr, char *s);
int func_select(const char key, va_list arg);
int ft_printf(const char *s, ...);

#endif