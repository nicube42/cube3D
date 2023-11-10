/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:31:44 by ndiamant          #+#    #+#             */
/*   Updated: 2022/11/08 10:58:39 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Select format and send tab
*/
void	ft_eval_format(t_print *tab, const char *format, int i)
{
	if ((format[i] != 'c') && (format[i] != 'd') && (format[i] != 's')
		&& (format[i] != '%') && (format[i] != 'u') && (format[i] != 'p')
		&& (format[i] != 'x') && (format[i] != 'X') && (format[i] != 'i'))
		i = ft_check_flag(tab, format, i);
	if (format[i] == 'c')
		ft_print_char(tab);
	if ((format[i] == 'd') || (format[i] == 'i'))
		ft_print_dec(tab);
	if (format[i] == 's')
		ft_print_string(tab);
	if (format[i] == '%')
		ft_print_percent(tab);
	if (format[i] == 'u')
		ft_print_unsint(tab);
	if (format[i] == 'p')
		ft_print_pointer(tab);
	if (format[i] == 'x')
		ft_print_hexa(tab, '0');
	if (format[i] == 'X')
		ft_print_hexa(tab, '1');
}

int	ft_check_flag(t_print *tab, const char *format, int i)
{
	while ((format[i] != 'c') && (format[i] != 'd') && (format[i] != 's')
		&& (format[i] != '%') && (format[i] != 'u') && (format[i] != 'p')
		&& (format[i] != 'x') && (format[i] != 'X'))
	{
		if (format[i] == '.')
		{
			tab->pnt = 1;
			i++;
		}
		if (format[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		if (format[i] == '0')
		{
			tab->zero = 1;
			i++;
		}
	}
	return (i);
}
