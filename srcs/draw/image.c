/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:35:02 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/04 18:56:28 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "draw.h"
#include <math.h>
#include <mlx.h>

static void	set_ray(t_data *data, t_ray *ray, double camera_x)
{
	ray->dir_x = data->player.dir_x + data->player.plane_x * camera_x;
	ray->dir_y = data->player.dir_y + data->player.plane_y * camera_x;
	ray->map_x = (int)(data->player.pos_x);
	ray->map_y = (int)(data->player.pos_y);
	calculate_delta_distance(ray);
	calculate_side_distance(data, ray);
}

static void	check_hit_point(t_data *data, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if ((data->map_data)[ray->map_x][ray->map_y] > 0)
			break ;
	}
}

static double	get_vertical_distance_to_wall(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		return (ray->map_x - data->player.pos_x + (1 - ray->step_x) / 2 / ray->dir_x);
	else
		return (ray->map_y - data->player.pos_y + (1 - ray->step_y) / 2 / ray->dir_y);
}

void	show_image(t_data *data)
{
	int		x;
	double	camera_x;
	double	perp_wall_dist;
	t_ray	ray;

	create_new_image(&(data->mlx));
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH;
		set_ray(data, &ray, camera_x);
		check_hit_point(data, &ray);
		perp_wall_dist = get_vertical_distance_to_wall(data, &ray);
		draw_line(&(data->mlx), x, perp_wall_dist);
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window, data->mlx.image, WIDTH, HEIGHT);
}
