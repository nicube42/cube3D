/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:55:14 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/19 12:15:06 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Alloue une chaine de caractère représentant l'entier 
 * passé en paramètre et la retourne.
*/

#include <stdlib.h>
#include "../../includes/libft.h"

static long	ft_sign(long nbr)
{
	if (nbr > 0)
		return (nbr);
	return (-nbr);
}

static size_t	ft_size(int n)
{
	if (n > 0)
		return (0);
	return (1);
}

static void	ft_test(char *s, size_t size)
{
	if (size == 0 && s[1] == '\0')
		*(s + size) = '0';
	else if (size == 0 && s[1] != '0')
		*(s + size) = '-';
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*s;
	long	nbr;

	nbr = n;
	nbr = ft_sign(nbr);
	size = ft_size(n);
	while (n)
	{
		n /= 10;
		size++;
	}
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (0);
	*(s + size--) = '\0';
	while (nbr > 0)
	{
		*(s + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	ft_test(s, size);
	return (s);
}
