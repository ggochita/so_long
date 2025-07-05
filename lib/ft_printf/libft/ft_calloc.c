/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:50:59 by ggochita          #+#    #+#             */
/*   Updated: 2023/01/20 17:51:49 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t memb, size_t size)
{
	void	*ptr;

	ptr = malloc(memb * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, memb * size);
	return (ptr);
}
