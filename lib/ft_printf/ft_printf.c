/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:10:46 by ggochita          #+#    #+#             */
/*   Updated: 2023/03/23 18:24:08 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	t_len;

	t_len = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		t_len++;
	}
	else if (format == 'd' || format == 'i')
		t_len += ft_putnbr_len(va_arg(args, int));
	else if (format == 's')
		t_len += ft_putstr_len(va_arg(args, char *));
	else if (format == 'p')
		t_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		t_len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		t_len += ft_print_hex(va_arg(args, unsigned int));
	else if (format == 'X')
		t_len += ft_print_hex_upr(va_arg(args, unsigned int));
	else if (format == '%')
		t_len += write(1, "%", 1);
	return (t_len);
}

int	ft_printf(const char *strf, ...)
{
	va_list	args;
	int		i;
	int		t_len;

	t_len = 0;
	i = 0;
	va_start(args, strf);
	while (strf[i])
	{
		if (strf[i] == '%')
		{
			t_len += ft_format(args, strf[i + 1]);
			i++;
		}
		else
			t_len += write(1, &strf[i], 1);
		i++;
	}
	va_end(args);
	return (t_len);
}
