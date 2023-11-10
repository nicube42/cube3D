/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifiers_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:35:04 by ndiamant          #+#    #+#             */
/*   Updated: 2022/11/08 10:29:28 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Print pointer
*/
void	ft_print_pointer(t_print *tab)
{
	unsigned long	p;

	p = va_arg(tab->args, unsigned long);
	if ((void *)p == NULL)
		ft_putstr("0x0", tab);
	else
	{
		ft_putstr("0x", tab);
		ft_putnbr_base_ul(p, "0123456789abcdef", tab);
	}
}

/*
 * Print hex
*/

void	ft_print_hexa(t_print *tab, int c)
{
	unsigned int	x;

	x = va_arg(tab->args, unsigned int);
	if (c == '0')
		ft_putnbr_base_ul(x, "0123456789abcdef", tab);
	else
		ft_putnbr_base_ul(x, "0123456789ABCDEF", tab);
}
