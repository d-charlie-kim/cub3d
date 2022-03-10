/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:44:25 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/10 15:21:42 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "structure.h"
#include "key_code.h"
#include "draw.h"
#include "clear.h"

static int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
	{
		printf("END\n");
		clear_all(data);
		exit (0);
	}
	if (key_code == W || key_code == A || key_code == S || key_code == D)
		player_movement(data, key_code);
	if (key_code == LEFT || key_code == RIGHT)
		player_rotation(data, key_code);
	return (0);
}

static int	x_icon(int key_code, t_data *data)
{
	(void)key_code;
	printf("END\n");
	clear_all(data);
	exit (0);
	return (0);
}

void	get_event(t_data *data)
{
	mlx_hook(data->mlx.window, 17, 0, x_icon, data);
	mlx_hook(data->mlx.window, 2, 1L >> 0, key_hook, data);
	mlx_loop(data->mlx.mlx_ptr);
}
