/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:17 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/08 19:51:46 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
				my_mlx_pixel_input(&(data->mlx), i, j, ceilling_color);
			else
				my_mlx_pixel_input(&(data->mlx), i, j, floor_color);
			j++;
		}
		i++;
	}
}

void	draw(t_data *data)
{
	set_player_position(data);
	show_image(data);
	get_event(data);
}
