/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:37:32 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/07 19:04:06 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "draw.h"

static int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0 && ray->step_x == 1)
		return (EAST);
	else if (ray->side == 0 && ray->step_x == -1)
		return (WEST);
	else if (ray->side == 1 && ray->step_y == 1)
		return (SOUTH);
	else
		return (NORTH);
}

static double	get_wall_x_coordinate(t_data *data, t_ray *ray, \
												double perp_wall_dist)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.pos_y + perp_wall_dist * ray->dir_y;
	else
		wall_x = data->player.pos_x + perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

static int	get_texture_x_coordinate(t_ray *ray, double wall_x, int tex_width)
{
	int tex_x;

							(void)ray;
	tex_x = (int)(wall_x * (double)tex_width);
	//if (ray->side == 0 && ray->dir_x > 0)             나중에 수정합시다
	//	tex_x = tex_width - tex_x - 1;
	//if (ray->side == 1 && ray->dir_y < 0)
	//	tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

static int	get_color(char *color_point, int endian)
{
	int	color;

	color = 0;
	if (endian == 1)
	{
		color += color_point[1];
		color <<= 8;
		color += color_point[2];
		color <<= 8;
		color += color_point[3];
	}
	else
	{
		color += color_point[2];
		color <<= 8;
		color += color_point[1];
		color <<= 8;
		color += color_point[0];
	}
	return (color);
}

void	draw_line(t_data *data, t_ray *ray, int x, double perp_wall_dist)
{
	int		tex_index;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		color;
	char	*color_point;
	double	wall_x;
	double	step;
	double	tex_pos;

	tex_index = get_texture_index(ray);
	line_height = (int)(HEIGHT / perp_wall_dist);
	wall_x = get_wall_x_coordinate(data, ray, perp_wall_dist);
	tex_x = get_texture_x_coordinate(ray, wall_x, data->textures.tex_width[tex_index]);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end > HEIGHT)
		draw_end = HEIGHT - 1;
	step = 1.0 * (data->textures.tex_height[tex_index]) / line_height;
	tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color_point = data->textures.tex[tex_index] + (data->textures.line_size[tex_index] * tex_y) + (data->textures.bits_per_pixel[tex_index] / 8 * tex_x);
		color = get_color(color_point, data->textures.endian[tex_index]);
		my_mlx_pixel_input(&(data->mlx), x, draw_start, color);
		draw_start++;
	}
}
