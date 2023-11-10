/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <asenaud@student.42lausanne.ch     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/02 09:59:58 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		fopen_str(const char *str, t_pars pars);
void	exit_error(const char *error_str, int error_num, t_pars pars);

static char	*filename_extract(const char *line_str)
{
	int		i_begin;
	int		j_end;
	char	*file_name;

	i_begin = 0;
	while (line_str[i_begin] == ' ')
		i_begin++;
	i_begin += 2;
	while (line_str[i_begin] == ' ')
		i_begin++;
	j_end = ft_strlen(line_str);
	while (line_str[j_end - 1] == ' ' || line_str[j_end - 1] == '\n')
		j_end--;
	file_name = malloc(sizeof(char) * (j_end - i_begin + 2));
	ft_strlcpy(file_name, line_str + i_begin, j_end - i_begin + 1);
	return (file_name);
}

char	*assign_filename(char *filename, char *actual_val, t_pars pars)
{
	if (actual_val != NULL)
		exit_error("[111] Texture a double", 1, pars);
	return (filename);
}

t_pars	save_texture(const char *line_str, char *filename, t_pars pars)
{
	int	i;

	i = 0;
	while (line_str[i] == ' ')
		i++;
	if (line_str[i] == 'N' && line_str[i + 1] == 'O')
		pars.north_file = assign_filename(filename, pars.north_file, pars);
	else if (line_str[i] == 'S' && line_str[i + 1] == 'O')
		pars.south_file = assign_filename(filename, pars.south_file, pars);
	else if (line_str[i] == 'E' && line_str[i + 1] == 'A')
		pars.east_file = assign_filename(filename, pars.east_file, pars);
	else if (line_str[i] == 'W' && line_str[i + 1] == 'E')
		pars.weast_file = assign_filename(filename, pars.weast_file, pars);
	else if (line_str[i] == 'D' && line_str[i + 1] == 'O')
		pars.door_file = assign_filename(filename, pars.door_file, pars);
	else
		exit_error("[112] Ligne invalide", 1, pars);
	return (pars);
}

t_pars	get_texture(char *line_str, t_pars pars)
{
	int		fd;
	char	*file_name;

	pars.str_to_free = line_str;
	file_name = filename_extract(line_str);
	fd = fopen_str(file_name, pars);
	close(fd);
	pars = save_texture(line_str, file_name, pars);
	pars.str_to_free = NULL;
	return (pars);
}
