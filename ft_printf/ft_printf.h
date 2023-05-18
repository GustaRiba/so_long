/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:22 by gmorais-          #+#    #+#             */
/*   Updated: 2022/12/02 12:20:15 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int n, int *len);
void	ft_unsigned_nbr(unsigned int n, int *len);
void	ft_hexa(unsigned int n, int *len, char esc);
int		ft_printf(const char *str, ...);
void	ft_putadress(unsigned long n, int *len);
void	percentage_check(char c, va_list *args, int *len, int *i);

#endif