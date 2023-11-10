/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenaud <asenaud@student.42lausanne.ch     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/02 09:59:58 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_pars(t_pars pars)
{
	int	i;

	if (pars.fd_cub)
		close(pars.fd_cub);
	if (pars.north_file)
		free(pars.north_file);
	if (pars.south_file)
		free(pars.south_file);
	if (pars.east_file)
		free(pars.east_file);
	if (pars.weast_file)
		free(pars.weast_file);
	if (pars.door_file)
		free(pars.door_file);
	i = 0;
	while (i < pars.nb_lines)
	{
		free(pars.wonder_map[i]);
		i++;
	}
	free(pars.wonder_map);
}

void	exit_error(const char *error_str, int error_num, t_pars pars)
{
	char	*disp_error;

	disp_error = ft_strjoin("Error\n", error_str);
	free_pars(pars);
	if (errno == 0)
		errno = error_num;
	perror(disp_error);
	free(disp_error);
	exit(error_num);
}

int	fopen_str(const char *str, t_pars pars)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_error("[021] open", errno, pars);
	return (fd);
}

void	print_map(int **wonder_map, int line_len, int nb_lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < line_len && wonder_map[i][j] != MAP_END)
		{
			printf("%d ", wonder_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

char	*clean_str(char *line_str)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(sizeof(char) * (ft_strlen(line_str) + 1));
	while (line_str[i] >= ' ' && line_str[i] <= '~')
	{
		new_line[i] = line_str[i];
		i++;
	}
	new_line[i] = '\0';
	free(line_str);
	return (new_line);
}
