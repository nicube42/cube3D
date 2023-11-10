/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:10:32 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/05 07:30:15 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Renvoie un tableau de chaines de caractères provenant 
 * de la chaine s et séparés par le caractère c.
*/

#include <stdlib.h>
#include "../../includes/libft.h"

static size_t	ft_countchar(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_countchar(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}
