/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:52 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/10 15:15:47 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "key_code.h"
#include "draw.h"
#include <math.h>

static void	move(t_data *data, double *pos_x, double *pos_y, int key_code)
{
	if (key_code == W)
	{
		*pos_x += data->player.dir_x / 10;
		*pos_y += data->player.dir_y / 10;
	}
	else if (key_code == S)
	{
		*pos_x -= data->player.dir_x / 10;
		*pos_y -= data->player.dir_y / 10;
	}
	else if (key_code == A)
	{
		*pos_x += data->player.dir_y / 10;
		*pos_y -= data->player.dir_x / 10;
	}
	else if (key_code == D)
	{
		*pos_x -= data->player.dir_y / 10;
		*pos_y += data->player.dir_x / 10;
	}
}

void	player_movement(t_data *data, int key_code)
{
	double	old_pos_x;
	double	old_pos_y;

	old_pos_x = data->player.pos_x;
	old_pos_y = data->player.pos_y;
	move(data, &(data->player.pos_x), &(data->player.pos_y), key_code);
	if (data->map_data[(int)(data->player.pos_y)][(int)old_pos_x] == '1')
		data->player.pos_y = old_pos_y;
	if (data->map_data[(int)(old_pos_y)][(int)data->player.pos_x] == '1')
		data->player.pos_x = old_pos_x;
	show_image(data);
}

static void	rotate_right(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed) \
		- data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed) \
		+ data->player.dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed) \
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) \
		+ data->player.plane_y * cos(rot_speed);
}

static void	rotate_left(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-rot_speed) \
		- data->player.dir_y * sin(-rot_speed);
	data->player.dir_y = old_dir_x * sin(-rot_speed) \
		+ data->player.dir_y * cos(-rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-rot_speed) \
		- data->player.plane_y * sin(-rot_speed);
	data->player.plane_y = old_plane_x * sin(-rot_speed) \
		+ data->player.plane_y * cos(-rot_speed);
}

void	player_rotation(t_data *data, int key_code)
{
	double	rot_speed;

	rot_speed = 0.1;
	if (key_code == RIGHT)
		rotate_right(data, rot_speed);
	else if (key_code == LEFT)
		rotate_left(data, rot_speed);
	show_image(data);
}
