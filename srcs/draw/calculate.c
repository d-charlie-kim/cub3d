/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:35:06 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/06 13:33:06 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "draw.h"
#include "key_code.h"
#include <math.h>

void	get_delta_distance(t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	get_side_distance(t_data *data, t_ray *ray)
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
	if (ray->dir_y < 0)
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

void	movement(t_data *data, int key_code)
{
	if (key_code == W)
	{
		data->player.pos_x += data->player.dir_x / 10;
		data->player.pos_y += data->player.dir_y / 10;
	}
	else if (key_code == S)
	{
		data->player.pos_x -= data->player.dir_x / 10;
		data->player.pos_y -= data->player.dir_y / 10;
	}
	else if (key_code == A)
	{
		data->player.pos_x += data->player.dir_y / 10;
		data->player.pos_y -= data->player.dir_x / 10;
	}
	else if (key_code == D)
	{
		data->player.pos_x -= data->player.dir_y / 10;
		data->player.pos_y += data->player.dir_x / 10;
	}
	show_image(data);
}

void	rotation(t_data *data, int key_code)
{
	(void)data;
	(void)key_code;
	return ;
}
