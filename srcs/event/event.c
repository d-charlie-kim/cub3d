/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:44:25 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/07 15:56:52 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "key_code.h"
#include "draw.h"
#include <mlx.h>
#include <stdio.h>

static int	key_hook(int key_code, t_data *data)
{
	printf("keycode : %d\n", key_code);
	if (key_code == W || key_code == A || key_code == S || key_code == D)
		player_movement(data, key_code);
	if (key_code == LEFT || key_code == RIGHT)
		player_rotation(data, key_code);
	return (0);
}

static int	mouse_hook(int key_code, int x, int y, t_data *data)
{
	if (key_code == LEFT_CLICK)
	{
		unsigned char	*color_point;

		color_point = (unsigned char *)(data->mlx.image_addr + (x * data->mlx.bits_per_pixel) + (y * data->mlx.line_size));
		printf("%d %d %d %d\n", color_point[0], color_point[1], color_point[2], color_point[3]);
	}
	return (0);
}

void	get_event(t_data *data)
{
	mlx_hook(data->mlx.window, 2, 1L >> 0, key_hook, data);
	mlx_mouse_hook(data->mlx.window, mouse_hook, data);
	mlx_loop(data->mlx.mlx_ptr);
}
