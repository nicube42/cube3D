/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:41:02 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 22:44:19 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strnstr() function locates the first occurrence of the null-terminated 
 * string needle in the string haystack, where not more than len characters 
 * are searched.
 * Characters that appear after a ‘\0’ character are not searched.
*/

#include <stddef.h>
#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*needle_tmp;
	char	*haystack_tmp;
	size_t	i;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	if ((!ft_strlen(haystack) || (len < ft_strlen(needle))))
		return (0);
	i = len - ft_strlen(needle) + 1;
	while (*haystack && i--)
	{
		needle_tmp = (char *)needle;
		haystack_tmp = (char *)haystack;
		while (*needle_tmp && *needle_tmp == *haystack_tmp)
		{
			needle_tmp++;
			haystack_tmp++;
		}
		if (!*needle_tmp)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
