/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:09 by timurray          #+#    #+#             */
/*   Updated: 2025/06/11 17:06:21 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

ssize_t str_len(char *s);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t char_handler(int c);
ssize_t str_handler(char *s);
ssize_t num_handler(long num, char *s);
ssize_t unum_handler(unsigned long long num, char *s);
ssize_t ptr_handler(void *ptr, char *s);
ssize_t func_select(const char key, va_list arg);
int ft_printf(const char *s, ...);

#endif