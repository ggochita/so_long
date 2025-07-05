/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:17:53 by ggochita          #+#    #+#             */
/*   Updated: 2023/03/23 18:18:35 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	int		i;
	int		t_len;
	char	*buffer;

	i = 0;
	t_len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	buffer = (char *)malloc(11 * sizeof(char));
	if (!buffer)
		return (0);
	while (n)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}
	t_len = i;
	while (i--)
		write(1, &buffer[i], 1);
	free(buffer);
	return (t_len);
}
