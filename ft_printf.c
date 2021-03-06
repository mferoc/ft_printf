/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathferr <mathferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 16:15:20 by mathferr          #+#    #+#             */
/*   Updated: 2020/10/29 21:42:31 by mathferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/* static void	zero_formatters(t_formatters *formatters) // REFACTOR FUNCTION NAME
{
	formatters->flags_len = 0;
	formatters->flag_minus = 0;
	formatters->flag_zero = 0;
	formatters->star = 0;
	formatters->point = 0;
	formatters->width = 0;
	formatters->precision = 0;
	formatters->specifier = '\0';
	formatters->flags = NULL;
}
 */
static char * build_flags(const char *fmt, t_formatters *formatters, va_list ap)
{
	while (!ft_is_specifier(fmt[formatters->fmt_position]))
	{
		if (ft_is_flag(fmt[formatters->fmt_position]))
			formatters->flags_len++;
		formatters->fmt_position++;
	}
	if (formatters->flags_len > 0)
		formatters->flags = ft_substr(fmt, (formatters->fmt_position - formatters->flags_len), formatters->flags_len);
	formatters->specifier = fmt[formatters->fmt_position];
	ft_specifier_manager(ap, formatters);
	free(formatters->flags);
	formatters->flags = NULL;
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_formatters	formatters;

	if (!format)
		return (-1);
	va_start(ap, format);
	intial_zero_state(&formatters);
	while (format[formatters.fmt_position])
	{
		if (format[formatters.fmt_position] != '%')
			ft_putchar_print_counter(format[formatters.fmt_position], &(formatters.printed_len));
		else if (format[formatters.fmt_position] == '%')
		{
			zero_formatters(&formatters);
			formatters.fmt_position++;
			build_flags(format, &formatters, ap);
		}
		formatters.fmt_position++;
	}
	va_end(ap);
	return (formatters.printed_len);
}

int	main(void) {
	//ft_printf("Print a percent sym\t%%\n");
	//ft_printf("Print c: char\t%c\tchar\t%c\n", 'X', 'Y');
	//ft_printf("Print s: str=\t%s\tstr=\t%s\n", "Groot", "I'M GROOT");
	//ft_printf("Print d and i: d=\t%d\ti=\t%i\n", -42, 777 - 666);
	//ft_printf("Print u: u=\t%u\tinvalid u=\t%u\n", 42, -666);
	//printf("OI EU SOU O GOKU\nPrint u: u=\t%u\tinvalid u=\t%u\n", 42, -666);
	//ft_printf("Print xX: x=\t%x\tX=\t%X\t0=\t%x\n", 666, 666, 0);
	//printf("OI EU SOU O GOKU\nPrint xX: x=\t%x\tX=\t%X\t0=\t%x\n", 666, 666, 0);
	//int x = 0;
	//int y = 0;
	//ft_printf("Print p: p=\t%p\tp=\t%p\tnull=%p\n", &x, &y, NULL);
	//printf("OI EU SOU O GOKU\nPrint p: p=\t%p\tp=\t%p\tnull=%p\n", &x, &y, NULL);
	//printf("Print s: str=\t%s\tstr=\t%s\tnull=%s\n", "Groot", "I'M GROOT", NULL);
	//ft_printf("Print s: str=\t%s\tstr=\t%s\tnull=%s\n", "Groot", "I'M GROOT", NULL);
	// int ret = ft_printf("Print p: p=\t%p\tp=\t%p\tnull=%p\n", &x, &y, NULL);
	// printf("ret = %d\n", ret);
	// printf("OI EU SOU O GOKU\n");
	// int ret_pf_real = printf("Print p: p=\t%p\tp=\t%p\tnull=%p\n", &x, &y, NULL);
	// printf("ret_pf_real = %d\n", ret_pf_real);
	// //ft_printf("%7 % % %% %z %k\n");
	// //printf("OI EU SOU O GOKU\n%7 % % %% %Z %k\n");
	// ft_printf("GROT = %5 % % %k %6t6 %tz %%\n\n");
	// printf("0 = %d\n", ft_isnum('0'));
	// printf("1 = %d\n", ft_isnum('1'));
	// printf("2 = %d\n", ft_isnum('2'));
	// printf("3 = %d\n", ft_isnum('3'));
	// printf("4 = %d\n", ft_isnum('4'));
	// printf("5 = %d\n", ft_isnum('5'));
	// printf("6 = %d\n", ft_isnum('6'));
	// printf("7 = %d\n", ft_isnum('7'));
	// printf("8 = %d\n", ft_isnum('8'));
	// printf("9 = %d\n", ft_isnum('9'));
	// printf("OUTRO = %d\n", ft_isnum('Z'));
	// printf("%d\n", 42);
	int r = ft_printf("s = %-*s\ts = %s\ts = %s\t s = %s\ts = %s\ts = %s\n", "GROOT", "BATMAN", "I'M BATMAN", "ECOLE42", "PUDIM", "GAMBIARRA");
	int rp = printf("s = %s\ts = %s\ts = %s\t s = %s\ts = %s\ts = %s\n", "GROOT", "BATMAN", "I'M BATMAN", "ECOLE42", "PUDIM", "GAMBIARRA");
	printf("meu = %d\treal = %d\n", r, rp);
	//ft_printf("fhk%dsrd%i\n", 1, 1);
	return (0);
}
