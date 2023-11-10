/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:44:01 by ndiamant          #+#    #+#             */
/*   Updated: 2023/05/10 11:32:37 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Ecrit le caractère 'c' sur le descripteur de fichier donné.
*/

#include <unistd.h>
#include "../../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	int	ret;

	ret = write (fd, &c, 1);
	(void) ret;
}
