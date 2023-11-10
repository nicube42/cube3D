/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/07 18:23:47 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		open_cub(int argc, char const **argv, t_pars pars);
t_pars	get_texture(const char *line_str, t_pars pars);
t_pars	get_color(const char *line_str, t_pars pars);
t_pars	map_generate(t_pars pars, char *line_str);
void	exit_error(const char *error_str, int error_num, t_pars pars);
char	*clean_str(char *line_str);

static t_pars	init_pars(int argc, char const **argv)
{
	t_pars	pars;

	pars.north_file = NULL;
	pars.south_file = NULL;
	pars.weast_file = NULL;
	pars.east_file = NULL;
	pars.door_file = NULL;
	pars.celling_set = 0;
	pars.floor_set = 0;
	pars.len_line = 0;
	pars.nb_lines = 0;
	pars.wonder_map = malloc(sizeof(int *));
	pars.str_to_free = NULL;
	pars.fd_cub = 0;
	pars.fd_cub = open_cub(argc, argv, pars);
	return (pars);
}

t_pars	choose_type_line(t_pars pars, char *line_str, int i)
{
	if (!ft_strncmp(line_str + i, "C ", 2)
		|| !ft_strncmp(line_str + i, "F ", 2))
		pars = get_color(line_str, pars);
	else if (!ft_strncmp(line_str + i, "NO ", 3)
		|| !ft_strncmp(line_str + i, "WE ", 3)
		|| !ft_strncmp(line_str + i, "SO ", 3)
		|| !ft_strncmp(line_str + i, "EA ", 3)
		|| !ft_strncmp(line_str + i, "DO ", 3))
		pars = get_texture(line_str, pars);
	else if (!(line_str[i] == '\0' || line_str[i] == '\n')
		&& !(line_str[i] == '1'))
		exit_error("[000] Ligne invalide", 1, pars);
	return (pars);
}

t_pars	parsing(int argc, char const **argv)
{
	t_pars	pars;
	char	*line_str;
	int		i;

	pars = init_pars(argc, argv);
	line_str = get_next_line(pars.fd_cub);
	while (line_str)
	{
		line_str = clean_str(line_str);
		i = 0;
		while (line_str[i] == ' ')
			i++;
		pars = choose_type_line(pars, line_str, i);
		if (line_str[i] == '1')
			break ;
		free(line_str);
		line_str = get_next_line(pars.fd_cub);
	}
	pars = map_generate(pars, line_str);
	return (pars);
}
