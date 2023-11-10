/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:14 by ndiamant          #+#    #+#             */
/*   Updated: 2022/11/08 10:28:11 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

/*
 * Put char and add 1 to total lengh
*/

void	ft_putchar(char c, t_print *tab)
{
	int	i;

	i = write (1, &c, 1);
	tab->tl += i;
}

/*
 * Malloc tab, gestion of variadic function, send information to format 
 * specifiers selection
*/

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_eval_format(tab, format, i + 1);
			i++;
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}

/*int main()
{
        char    c;
        int             i;
        char    *s;
    	char    *t = "def";
        unsigned int    u;
        unsigned int    x;
        int ret1;
        int ret2;

        c = 'm';
        i = 43;
        s = "nico";
        u = -42;
        x = 251672563;
        ret1 = ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", c,
	   	s, t, i, i, u, x, x);
        ret2 = printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", c,
	   	s, t, i, i, u, x, x);
        printf("%d, %d\n", ret1, ret2);
}*/
