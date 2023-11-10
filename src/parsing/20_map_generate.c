/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_map_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/07 18:06:41 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_pars	add_line(char *line_str, t_pars pars);
int		**adjust_map(int **wonder_map, int line_len, int nb_lines);
void	print_map(int **wonder_map, int line_len, int nb_lines);
void	exit_error(const char *error_str, int error_num, t_pars pars);
void	check_map(t_pars pars);
char	*clean_str(char *line_str);

t_pars	update_position(t_pars pars, int i, int j)
{
	pars.pos_num_column = j;
	pars.pos_num_line = i;
	pars.orientation = pars.wonder_map[i][j];
	pars.wonder_map[i][j] = GROUND;
	return (pars);
}

t_pars	set_position(t_pars pars)
{
	int	i;
	int	j;
	int	pos_find;

	pos_find = 0;
	i = -1;
	while (++i < pars.nb_lines)
	{
		j = -1;
		while (++j < pars.len_line)
		{
			if (pars.wonder_map[i][j] == 'N' || pars.wonder_map[i][j] == 'S' ||
				pars.wonder_map[i][j] == 'E' || pars.wonder_map[i][j] == 'W')
			{
				if (pos_find)
					exit_error("[200] Plusieurs pos de départ", 1, pars);
				pos_find = 1;
				pars = update_position(pars, i, j);
			}
		}
	}
	if (!pos_find)
		exit_error("[201] Pas de pos de départ", 1, pars);
	return (pars);
}

void	check_textures_exist(t_pars pars)
{
	if (!pars.north_file || !pars.south_file || !pars.weast_file
		|| !pars.east_file || !pars.door_file)
		exit_error("[202] Texture manquante", 1, pars);
	if (!pars.celling_set || !pars.floor_set)
		exit_error("[203] Couleur manquante", 1, pars);
}

t_pars	map_generate(t_pars pars, char *line_str)
{
	while (line_str)
	{
		line_str = clean_str(line_str);
		pars = add_line(line_str, pars);
		free(line_str);
		line_str = get_next_line(pars.fd_cub);
	}
	check_textures_exist(pars);
	pars.wonder_map = adjust_map(pars.wonder_map, pars.len_line, pars.nb_lines);
	pars = set_position(pars);
	print_map(pars.wonder_map, pars.len_line, pars.nb_lines);
	check_map(pars);
	return (pars);
}
