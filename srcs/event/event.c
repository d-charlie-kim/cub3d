/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:44:25 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/07 18:46:59 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "key_code.h"
#include "draw.h"
#include <mlx.h>

static int	key_hook(int key_code, t_data *data)
{
	printf("keycode : %d\n", key_code);
	if (key_code == ESC)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window);
		printf("END\n");
		exit (0);
	}
	if (key_code == W || key_code == A || key_code == S || key_code == D)
		player_movement(data, key_code);
	if (key_code == LEFT || key_code == RIGHT)
		player_rotation(data, key_code);
	return (0);
}

static int	x_icon(int key_code)
{
	(void)key_code;
	printf("END\n");
	exit (0);
	return (0);
}

void	get_event(t_data *data)
{
	mlx_hook(data->mlx.window, 17, 0, x_icon, NULL);
	mlx_hook(data->mlx.window, 2, 1L >> 0, key_hook, data);
	mlx_loop(data->mlx.mlx_ptr);
}
