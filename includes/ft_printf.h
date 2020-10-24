/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathferr <mathferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 04:42:40 by mathferr          #+#    #+#             */
/*   Updated: 2020/10/23 05:22:46 by mathferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define	FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void	ft_print_percent(void);
void	ft_putchar(const char c);
void	ft_putstr(const char *s);
int		ft_printf(const char *format, ...);
void	ft_specifier_manager(char specifier);

# endif