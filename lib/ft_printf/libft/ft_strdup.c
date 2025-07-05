/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:53:03 by ggochita          #+#    #+#             */
/*   Updated: 2023/01/20 18:53:04 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*nstr;
	size_t	len;

	len = ft_strlen(s) + 1;
	nstr = malloc(len);
	if (!nstr)
		return (NULL);
	nstr = ft_memcpy(nstr, s, len);
	return (nstr);
}
