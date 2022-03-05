/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:17 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/05 12:28:28 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "struct.h"
#include "event.h"

void	put_color_floor_and_ceilling(t_data *data)
{
	int	i;
	int	j;
	int	floor_color;
	int	ceilling_color;

	floor_color = get_rgb_code(data->textures.floor);
	ceilling_color = get_rgb_code(data->textures.ceilling);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				my_mlx_pixel_input(&(data->mlx), i, j, floor_color);
			else
				my_mlx_pixel_input(&(data->mlx), i, j, ceilling_color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_mlx *mlx, t_ray *ray, int x, double distance)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT / distance);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end > HEIGHT)
		draw_end = HEIGHT - 1;
	while (draw_start <= draw_end)
	{
		if (ray->side == 0 && ray->step_x == 1)
			my_mlx_pixel_input(mlx, x, draw_start, 0x00FF00FF); // 서쪽 벽
		else if (ray->side == 0 && ray->step_x == -1)
			my_mlx_pixel_input(mlx, x, draw_start, 0x00FFFF00); // 동쪽 벽
		else if (ray->side == 1 && ray->step_y == 1)
			my_mlx_pixel_input(mlx, x, draw_start, 0x00000000); // 북쪽 벽
		else if (ray->side == 1 && ray->step_y == -1)	
			my_mlx_pixel_input(mlx, x, draw_start, 0x0000FF00); // 남쪽 벽
		draw_start++;
	}
}

void	draw(t_data *data)
{
	set_player_position(data);
	show_image(data);     // jaejeong
	while (1);
	//get_event(data);            // 나중에 같이
}
