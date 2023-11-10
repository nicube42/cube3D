/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:46:10 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 16:13:26 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 * The memcmp() function returns zero if the two strings are identical, 
 * otherwise returns the difference between the first two differing bytes 
 * (treated as unsigned char values, so that ‘\200’ is greater than ‘\0’, 
 * for example). Zero-length strings are always identical.
*/

#include <stddef.h>
#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
