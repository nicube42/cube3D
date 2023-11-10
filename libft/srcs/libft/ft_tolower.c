/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:23:40 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 16:20:37 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The tolower() function converts an upper-case letter to the corresponding 
 * lower-case letter.
 * The argument must be representable as an unsigned char or the value of EOF.
 * If the argument is an upper-case letter, the tolower() function returns the 
 * corresponding lower-case letter if there is one;
 * otherwise, the argument is returned unchanged.
*/

#include "../../includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
