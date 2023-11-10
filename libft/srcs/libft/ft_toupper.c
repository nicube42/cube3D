/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:13:13 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 16:20:52 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The toupper() function converts a lower-case letter to the corresponding 
 * upper-case letter.
 * The argument must be representable as an unsigned char or the value of EOF.
 * If the argument is a lower-case letter, the toupper() function returns the 
 * corresponding upper-case letter if there is one; otherwise, the argument is 
 * returned unchanged.
*/

#include "../../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
