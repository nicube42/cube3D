/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:26 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 22:42:08 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strcmp() and strncmp() functions lexicographically compare the 
 * null-terminated strings s1 and s2.
 * The strncmp() function compares not more than n characters.
 * Because strncmp() is designed for comparing strings rather than binary data, 
 * characters that appear after a ‘\0’ character are not compared.
 * The strcmp() and strncmp() functions return an integer greater than, equal to,
 * or less than 0, according as the string s1 is greater than, equal to, or 
 * less than the string s2.
 * The comparison is done using unsigned characters, so that ‘\200’ is 
 * greater than ‘\0’.
*/

#include <stddef.h>
#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
