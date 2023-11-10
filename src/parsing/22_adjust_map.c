/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_adjust_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <asenaud@student.42lausanne.ch     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/02 09:59:58 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_pars	add_line(char *line_str, t_pars pars);

static int	*adjust_line(int *line_int, int line_len)
{
	int	i;
	int	*new_line;

	new_line = malloc(sizeof(int) * line_len);
	i = 0;
	while (i < line_len && line_int[i] != MAP_END)
	{
		new_line[i] = line_int[i];
		i++;
	}
	while (i < line_len)
	{
		new_line[i] = BLANK;
		i++;
	}
	free(line_int);
	return (new_line);
}

int	**adjust_map(int **wonder_map, int line_len, int nb_lines)
{
	int	i;

	i = 0;
	while (i < nb_lines)
	{
		wonder_map[i] = adjust_line(wonder_map[i], line_len);
		i++;
	}
	return (wonder_map);
}
