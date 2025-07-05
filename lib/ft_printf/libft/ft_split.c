/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:16:33 by ggochita          #+#    #+#             */
/*   Updated: 2023/01/20 18:44:48 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_splitcp(char c, char const *s, char **result)
{
	int		oldi;
	int		i;
	int		sp;

	i = 0;
	sp = 0;
	oldi = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			oldi = i;
			while (s[i] && s[i] != c)
				i++;
			result[sp] = ft_substr(s, oldi, i - oldi);
			if (!result[sp])
				return (NULL);
			sp++;
		}
	}
	result[sp] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;

	if (!s)
		return (NULL);
	count = ft_split_count(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	result = ft_splitcp(c, s, result);
	return (result);
}
