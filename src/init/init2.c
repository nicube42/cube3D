/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:10:13 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/08 13:28:56 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exit_error(const char *error_str, int error_num, t_pars pars);

void	free_all_doors(t_door ***doors, int map_height)
{
	int	i;

	i = -1;
	if (doors == NULL || *doors == NULL)
		return ;
	while (++i < map_height)
	{
		free((*doors)[i]);
		(*doors)[i] = NULL;
	}
	free(*doors);
	*doors = NULL;
}

void	free_door(int y, t_door **doors, t_nest *nest)
{
	while (y-- > 0)
		free(doors[y]);
	free(doors);
	exit_error("[init 1] Malloc error", 1, nest->pars);
}

void	transform_orientation_x(t_nest *nest, const double plane_value)
{
	if (nest->pars.orientation == 'E')
	{
		nest->rc.dir_x = 0.0;
		nest->rc.dir_y = 1.0;
		nest->rc.plane_x = plane_value;
		nest->rc.plane_y = 0.0;
	}
	if (nest->pars.orientation == 'W')
	{
		nest->rc.dir_x = 0.0;
		nest->rc.dir_y = -1.0;
		nest->rc.plane_x = -plane_value;
		nest->rc.plane_y = 0.0;
	}
}

void	transform_orientation_y(t_nest *nest)
{
	const double	plane_value = 0.66;

	if (nest->pars.orientation == 'N')
	{
		nest->rc.dir_x = -1.0;
		nest->rc.dir_y = 0.0;
		nest->rc.plane_x = 0.0;
		nest->rc.plane_y = plane_value;
	}
	if (nest->pars.orientation == 'S')
	{
		nest->rc.dir_x = 1.0;
		nest->rc.dir_y = 0.0;
		nest->rc.plane_x = 0.0;
		nest->rc.plane_y = -plane_value;
	}
	transform_orientation_x(nest, plane_value);
}

void	free_all(t_nest *nest)
{
	free_pars(nest->pars);
	free_all_doors(&nest->rc.doors, nest->rc.len_line);
}
