/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_open_cub.c                                      :+:      :+:    :+:   */
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

static void	check_cub(char const **argv, t_pars pars)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (len <= 4)
		exit_error("[031] .cub", 1, pars);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
		exit_error("[032] .cub", 1, pars);
}

int	open_cub(int argc, char const **argv, t_pars pars)
{
	if (argc != 2)
		exit_error("[033] ./cub3d myfile.cub", 1, pars);
	check_cub(argv, pars);
	return (fopen_str(argv[1], pars));
}
