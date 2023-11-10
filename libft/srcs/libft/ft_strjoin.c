/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:32:45 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/09 08:11:36 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Alloue assez de place avec malloc et retourne la chaine concaténée de s1 et s2
*/

#include <stdlib.h>
#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	ft_strlcpy(s, s1, len + 1);
	ft_strlcat(s, s2, len + 1);
	return (s);
}
