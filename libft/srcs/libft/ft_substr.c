/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:19:02 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/19 14:17:27 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Alloue avec malloc une nouvelle chaine de caractère issue de la chaine s. 
 * Elle commence à l'index start et a pour taille maximale len.
*/

#include <stdlib.h>
#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (len != 0 && ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	new_s = (char *)malloc(len + 1);
	if (!new_s)
		return (0);
	if (len != 0)
		ft_strlcpy(new_s, s + start, len + 1);
	else
		new_s[0] = '\0';
	return (new_s);
}
