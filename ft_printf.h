/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:09 by timurray          #+#    #+#             */
/*   Updated: 2025/06/13 09:13:00 by timurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(const char c, const int fd);
int		char_handler(const int c);
ssize_t	func_select(const char key, va_list *args);
ssize_t	ft_str_len(const char *s);
ssize_t	ft_putstr_fd(const char *s, const int fd);
ssize_t	str_handler(const char *s);
ssize_t	num_handler(const long num, const char *s);
ssize_t	unum_handler(const unsigned long long num, const char *s);
ssize_t	ptr_handler(const void *ptr, const char *s);

#endif