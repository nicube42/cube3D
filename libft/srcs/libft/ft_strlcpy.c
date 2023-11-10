/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:22:51 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 16:17:30 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strlcpy() and strlcat() functions copy and concatenate strings with the 
 * same input parameters and output result as snprintf(3).
 * They are designed to be safer, more consistent, and less error prone 
 * replacements for the easily misused functions strncpy(3) and strncat(3).
 * strlcpy() and strlcat() take the full size of the destination buffer and 
 * guarantee NUL-termination if there is room.
 * Note that room for the NUL should be included in dstsize.
 * strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
 * NUL-terminating the result if dstsize is not 0.
*/

#include <stddef.h>
#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
