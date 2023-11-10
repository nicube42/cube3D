/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:33:20 by ndiamant          #+#    #+#             */
/*   Updated: 2022/11/07 23:11:47 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Print char
*/
void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	ft_putchar(c, tab);
}

/*
 * Print int
*/

void	ft_print_dec(t_print *tab)
{
	int	i;

	i = va_arg(tab->args, int);
	ft_putnbr(i, tab);
}

/*
 * Print char *
*/

void	ft_print_string(t_print *tab)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(tab->args, char *);
	if (s == NULL)
		ft_putstr("(null)", tab);
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], tab);
			i++;
		}
	}
}

/*
 * Print % sign
*/

void	ft_print_percent(t_print *tab)
{
	ft_putchar('%', tab);
}

/*
 * Print unsigned int
*/

void	ft_print_unsint(t_print *tab)
{
	unsigned int	i;

	i = va_arg(tab->args, unsigned int);
	ft_putunsint(i, tab);
}
