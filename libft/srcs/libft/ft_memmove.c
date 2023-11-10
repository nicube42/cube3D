/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:27:52 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 22:39:30 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy len bytes from src to dst.
 * Return dst
*/

#include <stddef.h>
#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*buffer;

	if (!dst && !src)
		return (0);
	buffer = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	else
	{
		while (len--)
			*(char *)dst++ = *(char *)src++;
	}
	return (buffer);
}
