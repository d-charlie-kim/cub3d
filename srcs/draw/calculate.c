/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:35:06 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/07 19:03:41 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "draw.h"
#include "key_code.h"

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
		ray->side_dist_x = \
			(data->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = \
			(ray->map_x + 1.0 - data->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = \
			(data->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = \
			(ray->map_y + 1.0 - data->player.pos_y) * ray->delta_dist_y;
	}
}

void	player_movement(t_data *data, int key_code)
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

void	player_rotation(t_data *data, int key_code)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotSpeed;

	rotSpeed = 0.1;
	if (key_code == RIGHT)
	{
		old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(rotSpeed) \
			- data->player.dir_y * sin(rotSpeed);
		data->player.dir_y = old_dir_x * sin(rotSpeed) \
			+ data->player.dir_y * cos(rotSpeed);
		old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(rotSpeed) \
			- data->player.plane_y * sin(rotSpeed);
		data->player.plane_y = old_plane_x * sin(rotSpeed) \
			+ data->player.plane_y * cos(rotSpeed);
	}
	else if (key_code == LEFT)
	{
		old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-rotSpeed) \
			- data->player.dir_y * sin(-rotSpeed);
		data->player.dir_y = old_dir_x * sin(-rotSpeed) \
			+ data->player.dir_y * cos(-rotSpeed);
		old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(-rotSpeed) \
			- data->player.plane_y * sin(-rotSpeed);
		data->player.plane_y = old_plane_x * sin(-rotSpeed) \
			+ data->player.plane_y * cos(-rotSpeed);
	}
	show_image(data);
}
