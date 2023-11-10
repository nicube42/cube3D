/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:36:01 by ndiamant          #+#    #+#             */
/*   Updated: 2022/11/08 10:29:07 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Put string
*/

void	ft_putstr(char *str, t_print *tab)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		ft_putchar(str[a], tab);
		a++;
	}
}

/*
* Check if base is valid
*/

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

/*
 * Write an hex number
*/

void	ft_putnbr_base_ul(unsigned long n, char *base, t_print *tab)
{
	unsigned long	base_len;

	if (check_base(base))
	{
		base_len = 0;
		while (base[base_len])
			base_len++;
		if (n > base_len - 1)
		{
			ft_putnbr_base_ul(n / base_len, base, tab);
			n %= base_len;
		}
		ft_putchar(base[n], tab);
	}
}

/* 
 * Write an int
*/

void	ft_putnbr(int nb, t_print *tab)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', tab);
		ft_putchar('2', tab);
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', tab);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, tab);
		ft_putnbr(nb % 10, tab);
	}
	else
		ft_putchar(nb + '0', tab);
}

/*
 * Write an unsigned int
*/

void	ft_putunsint(unsigned int nb, t_print *tab)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, tab);
		ft_putnbr(nb % 10, tab);
	}
	else
		ft_putchar(nb + '0', tab);
}
