/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:59:52 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/19 12:15:24 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The strdup() function allocates sufficient memory for a copy of 
 * the string s1, does the copy, and returns a pointer to it.
 * The pointer may subsequently be used as an argument to the
 * function free(3).
 * If insufficient memory is available, NULL is returned
*/

#include <stdlib.h>
#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
