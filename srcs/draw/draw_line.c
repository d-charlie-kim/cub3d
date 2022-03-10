/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:37:32 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/10 15:15:21 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structure.h"
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

static int	get_texture_x_coordinate(t_data *data, t_ray *ray,
		double perp_wall_dist, int tex_index)
{
	int		tex_x;
	int		tex_width;
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.pos_y + perp_wall_dist * ray->dir_y;
	else
		wall_x = data->player.pos_x + perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_width = data->textures.tex_width[tex_index];
	tex_x = (int)(wall_x * (double)tex_width);
	if (ray->side == 0 && ray->dir_x < 0)
		tex_x = tex_width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

static int	get_color(t_data *data, t_tex tex, int endian)
{
	int				color;
	unsigned char	*color_point;

	color = 0;
	color_point = (unsigned char *)(data->textures.tex[tex.index]
			+ (data->textures.line_size[tex.index] * tex.y)
			+ (data->textures.bits_per_pixel[tex.index] / 8 * tex.x));
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
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	t_tex	tex;

	tex.index = get_texture_index(ray);
	line_height = (int)(HEIGHT / perp_wall_dist);
	tex.x = get_texture_x_coordinate(data, ray, perp_wall_dist, tex.index);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	tex.step = 1.0 * (data->textures.tex_height[tex.index]) / line_height;
	tex.pos = (draw_start - HEIGHT / 2 + line_height / 2) * tex.step;
	while (draw_start <= draw_end)
	{
		tex.y = (int)tex.pos;
		tex.pos += tex.step;
		color = get_color(data, tex, data->textures.endian[tex.index]);
		my_mlx_pixel_input(&(data->mlx), x, draw_start, color);
		draw_start++;
	}
}
