/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:49:38 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/19 14:18:40 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strchr() function locates the first occurrence of c (converted to a char) 
 * in the string pointed to by s.
 * The terminating null character is considered to be part of the string;
 * therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
 * The strrchr() function is identical to strchr(), except it locates the last 
 * occurrence of c.
 * The functions strchr() and strrchr() return a pointer to the located character
 * or NULL if the character does not appear in the string.
*/

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		++s;
	}
	if (!((char)c))
		ret = ((char *)s);
	return (ret);
}
