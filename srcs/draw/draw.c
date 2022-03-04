/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:17 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/04 19:23:26 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "struct.h"
#include "event.h"
#include <stdio.h>

void	draw_line(t_mlx *mlx, int x, double distance)
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
		my_mlx_pixel_input(mlx, x, draw_start, 0x00FF00FF);
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
