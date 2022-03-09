/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:52 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/09 16:55:12 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "key_code.h"
#include "draw.h"
#include <math.h>

void	player_movement(t_data *data, int key_code)
{
	double	old_pos_x;
	double	old_pos_y;

	old_pos_x = data->player.pos_x;
	old_pos_y = data->player.pos_y;
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
	if (data->map_data[(int)(data->player.pos_y)][(int)old_pos_x] == '1')
		data->player.pos_y = old_pos_y;
	if (data->map_data[(int)(old_pos_y)][(int)data->player.pos_x] == '1')
		data->player.pos_x = old_pos_x;
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
