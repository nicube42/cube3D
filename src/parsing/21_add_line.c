/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_add_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/09 14:37:25 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	exit_error(const char *error_str, int error_num, t_pars pars);

int	*str_to_line(char *line_str, int len, t_pars pars)
{
	int	*new_line;
	int	i;

	new_line = malloc(sizeof(int) * (len + 1));
	i = 0;
	while (line_str[i] && line_str[i] != '\n')
	{
		if (line_str[i] == '0')
			new_line[i] = GROUND;
		else if (line_str[i] == '1')
			new_line[i] = WALL;
		else if (line_str[i] == '2')
			new_line[i] = DOOR;
		else if (line_str[i] == ' ')
			new_line[i] = BLANK;
		else if (line_str[i] == 'N' || line_str[i] == 'S'
			|| line_str[i] == 'W' || line_str[i] == 'E')
			new_line[i] = line_str[i];
		else
			exit_error("[211] Map uniqument 0/1/2/espace", 1, pars);
		i++;
	}
	new_line[i] = MAP_END;
	return (new_line);
}

t_pars	add_line(char *line_str, t_pars pars)
{
	int	len;
	int	**new_map;
	int	i;

	pars.str_to_free = line_str;
	if (line_str[0] == '\0')
		exit_error("[212] Ligne vide dans la map", 1, pars);
	len = ft_strlen(line_str);
	if (line_str[len - 1] == '\n')
		len--;
	if (len > pars.len_line)
		pars.len_line = len;
	new_map = malloc(sizeof(int *) * (pars.nb_lines + 1));
	i = 0;
	while (i < pars.nb_lines)
	{
		new_map[i] = pars.wonder_map[i];
		i++;
	}
	new_map[i] = str_to_line(line_str, len, pars);
	free(pars.wonder_map);
	pars.wonder_map = new_map;
	pars.nb_lines++;
	pars.str_to_free = NULL;
	return (pars);
}
