/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <asenaud@student.42lausanne.ch     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/02 09:59:58 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	exit_error(const char *error_str, int error_num, t_pars pars);

void	check_line(int *line_int, int line_len, t_pars pars)
{
	int	i;

	i = 0;
	while (i < line_len)
	{
		while ((i < line_len) && line_int[i] == BLANK)
			i++;
		if (i == line_len)
			break ;
		if (line_int[i] != WALL)
			exit_error("[220] Mur ouvert", 1, pars);
		while ((i < line_len) && line_int[i] != BLANK)
			i++;
		if (line_int[i - 1] != WALL)
			exit_error("[221] Mur non fermer", 1, pars);
		i++;
	}
}

void	check_column(int **line_int, int line_len,
	int nb_lines, t_pars pars)
{
	int	i;
	int	j;

	j = 0;
	while (j < line_len)
	{
		i = 0;
		while (i < nb_lines)
		{
			while ((i < nb_lines) && line_int[i][j] == BLANK)
				i++;
			if (i == nb_lines)
				break ;
			if (line_int[i][j] != WALL)
				exit_error("[222] Mur ouvert", 1, pars);
			while ((i < nb_lines) && line_int[i][j] != BLANK)
				i++;
			if (line_int[i - 1][j] != WALL)
				exit_error("[223] Mur non fermer", 1, pars);
			i++;
		}
		j++;
	}
}

int	has_door(int **line_int, int line_len, int nb_lines)
{
	int	i;
	int	j;

	j = 0;
	while (j < line_len)
	{
		i = 0;
		while (i < nb_lines)
		{
			if (line_int[i][j] == DOOR)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	check_map(t_pars pars)
{
	int	i;

	i = 0;
	while (i < pars.nb_lines)
	{
		check_line(pars.wonder_map[i], pars.len_line, pars);
		i++;
	}
	check_column(pars.wonder_map, pars.len_line, pars.nb_lines, pars);
	if (has_door(pars.wonder_map, pars.len_line, pars.nb_lines))
	{
		if (pars.door_file == NULL)
			exit_error("[231] Texture de porte manquante", 1, pars);
	}
}
