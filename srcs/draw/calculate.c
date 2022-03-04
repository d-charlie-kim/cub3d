/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:35:06 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/04 18:48:54 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "draw.h"
#include <math.h>

void	calculate_delta_distance(t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(ray->dir_x);
	if (ray->dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(ray->dir_y);
}

void	calculate_side_distance(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_x < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.pos_y) * ray->delta_dist_y;
	}
}
