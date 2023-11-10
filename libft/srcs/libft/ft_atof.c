/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:05:28 by ndiamant          #+#    #+#             */
/*   Updated: 2023/04/04 09:06:25 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_atof_prep(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' \
		|| *str == '\r' || *str == ' ')
		++str;
	ft_atof(str);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	ret;
	double	power;

	power = 1.0;
	ret = 0.0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10.0 + sign * (*str - '0');
		str++;
	}	
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		ret = ret * 10.0 + (*str - '0');
		power *= 10.0;
		str++;
	}
	return (ret / power);
}
