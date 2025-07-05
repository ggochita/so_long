/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:25:05 by ggochita          #+#    #+#             */
/*   Updated: 2023/03/23 18:27:23 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int c)
{
	int	t_len;

	t_len = 0;
	ft_putnbr_fd(c, 1);
	if (c < 0)
	{
		while (c != 0)
		{
			c /= 10;
			++t_len;
		}
		t_len++;
	}
	else if (c > 9)
	{
		while (c != 0)
		{
			c /= 10;
			++t_len;
		}
	}
	else
		++t_len;
	return (t_len);
}
