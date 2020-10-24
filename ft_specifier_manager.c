/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathferr <mathferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:00:40 by mathferr          #+#    #+#             */
/*   Updated: 2020/10/24 16:06:34 by mathferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_specifier_manager(char specifier, va_list ap) //recebendo ap para imprimir args
{
	if (specifier == 'c')
		ft_print_c(ap);
	else if (specifier == 's')
		ft_print_s(ap);
	else if (specifier == 'd' || specifier == 'i')
		ft_print_di(ap);
	else if (specifier == 'u')
		ft_putchar('u'); //MODIFICAR
	else if (specifier == 'x' || specifier == 'X')
		ft_putchar('x'); //MODIFICAR
	else if (specifier == '%')
		ft_print_percent();
}