/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:51:01 by ndiamant          #+#    #+#             */
/*   Updated: 2022/10/17 22:45:01 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The calloc() function contiguously allocates enough space 
 * for count objects that are size bytes of memory each and 
 * returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
*/

#include <stdlib.h>
#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}
