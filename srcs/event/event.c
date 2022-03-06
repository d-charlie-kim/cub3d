/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:44:25 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/06 13:34:35 by jaejeong         ###   ########.fr       */
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
	//if (key_code == ESC)
	//	free_and_exit();
	if (key_code == W || key_code == A || key_code == S || key_code == D)
		movement(data, key_code);
	if (key_code == LEFT || key_code == RIGHT)
		rotation(data, key_code);
	return (0);
}

//static int	mouse_hook()
//{
	
//}

void	get_event(t_data *data)
{
	mlx_key_hook(data->mlx.window, key_hook, data);
	//mlx_mouse_hook(data->mlx.window, mouse_hook, data);
	mlx_loop(data->mlx.mlx_ptr);
}
