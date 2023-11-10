/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/09 09:42:03 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	exit_error(const char *error_str, int error_num, t_pars pars);

static int	str_num(const char *line_str, t_pars pars)
{
	int		i;
	char	*num_str;
	int		num;

	i = 0;
	while (ft_isdigit(line_str[i]))
		i++;
	num_str = malloc(sizeof(char) * (i + 1));
	ft_strlcpy(num_str, line_str, i + 1);
	num = ft_atoi(num_str);
	if ((num < 0) || (num > 255))
		exit_error("[121] Hors de 0-255", 1, pars);
	free(num_str);
	return (num);
}

static int	pass_number(int i_begin, const char *line_str,
	int is_end, t_pars pars)
{
	while (ft_isdigit(line_str[i_begin]))
		i_begin++;
	if ((is_end == 0) && (line_str[i_begin] == ','))
		i_begin++;
	else if (is_end == 1)
	{
		while (line_str[i_begin] == ' ')
			i_begin++;
		if (line_str[i_begin] != '\0' && line_str[i_begin] != '\n')
			exit_error("[122] 255,255,255", 1, pars);
	}
	else
		exit_error("[123] 255,255,255", 1, pars);
	return (i_begin);
}

static unsigned long	get_r_g_b(int i_begin,
	const char *line_str, t_pars pars)
{
	int	r;
	int	g;
	int	b;

	r = str_num(line_str + i_begin, pars);
	i_begin = pass_number(i_begin, line_str, 0, pars);
	g = str_num(line_str + i_begin, pars);
	i_begin = pass_number(i_begin, line_str, 0, pars);
	b = str_num(line_str + i_begin, pars);
	i_begin = pass_number(i_begin, line_str, 1, pars);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static t_pars	save_color(t_pars pars, unsigned long rgb, char c)
{
	if (c == 'C' && (pars.celling_set == 0))
	{
		pars.celling_color = rgb;
		pars.celling_set = 1;
	}
	else if (c == 'F' && (pars.floor_set == 0))
	{
		pars.floor_color = rgb;
		pars.floor_set = 1;
	}
	else
		exit_error("[124] Ligne/couleur invalide", 1, pars);
	return (pars);
}

t_pars	get_color(char *line_str, t_pars pars)
{
	int				i_begin;
	char			c;
	unsigned long	rgb;

	pars.str_to_free = line_str;
	i_begin = 0;
	while (line_str[i_begin] == ' ')
		i_begin++;
	c = line_str[i_begin];
	i_begin++;
	while (line_str[i_begin] == ' ')
		i_begin++;
	rgb = get_r_g_b(i_begin, line_str, pars);
	pars = save_color(pars, rgb, c);
	pars.str_to_free = NULL;
	return (pars);
}
