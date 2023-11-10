/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:17:46 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 22:33:16 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy n bytes from src to dst. If overlap behavior is undefined = use memmove.
 * Return dst.
*/

#include <stddef.h>
#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*buffer;

	if (!dst && !src)
		return (0);
	buffer = dst;
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (buffer);
}
