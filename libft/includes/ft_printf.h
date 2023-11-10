/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:42:51 by ndiamant          #+#    #+#             */
/*   Updated: 2023/01/10 16:06:28 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
}	t_print;

int		ft_printf(const char *format, ...);
t_print	*ft_initialise_tab(t_print *tab);
void	ft_eval_format(t_print *tab, const char *format, int i);
int		ft_check_flag(t_print *tab, const char *format, int i);
void	ft_print_char(t_print *tab);
void	ft_print_dec(t_print *tab);
void	ft_print_string(t_print *tab);
void	ft_print_percent(t_print *tab);
void	ft_print_unsint(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_hexa(t_print *tab, int c);
void	ft_putchar(char c, t_print *tab);
void	ft_putstr(char *str, t_print *tab);
void	ft_putnbr_base_ul(unsigned long n, char *base, t_print *tab);
void	ft_putnbr(int nb, t_print *tab);
void	ft_putunsint(unsigned int nb, t_print *tab);

#endif
