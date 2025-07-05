/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:26:18 by ggochita          #+#    #+#             */
/*   Updated: 2023/03/23 21:29:28 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upr(unsigned int num)
{
	char			*hex;
	int				len;

	len = ft_hex_len(num);
	hex = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (0);
	hex[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (num % 16 < 10)
			hex[len] = num % 16 + 48;
		else
			hex[len] = num % 16 + 55;
		num /= 16;
		len--;
	}
	ft_putstr_fd(hex, 1);
	len = 0;
	while (hex[len])
		len++;
	free (hex);
	return (len);
}
