/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:49:30 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/07 14:34:12 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_door	*check_for_door(t_rc *rc)
{
	int	hit;

	calculate_ray_direction(rc, SCREEN_WIDTH / 2, SCREEN_WIDTH);
	calculate_delta_dist(rc);
	calculate_side_dist(rc);
	hit = 0;
	while (hit == 0)
	{
		prep_dda(rc);
		if (rc->worldmap[rc->map_x][rc->map_y] > 0)
		{
			if (rc->worldmap[rc->map_x][rc->map_y] == 2)
			{
				return (&rc->doors[rc->map_x][rc->map_y]);
			}
			hit = 1;
		}
	}
	return (NULL);
}

int	action(t_rc *rc)
{
	t_door	*door;

	door = check_for_door(rc);
	if (door != NULL)
	{
		if (door->state == 1)
		{
			door->state = 2;
		}
		else if (door->state == 2)
		{
			door->state = 1;
		}
	}
	return (0);
}
