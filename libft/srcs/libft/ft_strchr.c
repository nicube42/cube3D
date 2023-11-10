/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:27:00 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 16:15:43 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strchr() function locates the first occurrence of c 
 *(converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be part of the string;
 * therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
 * The strrchr() function is identical to strchr(), except it locates 
 * the last occurrence of c.
 * The functions strchr() and strrchr() return a pointer to the located 
 * character, or NULL if the character does not appear in    the string.
*/

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return ((0));
	}
	return ((char *)s);
}
