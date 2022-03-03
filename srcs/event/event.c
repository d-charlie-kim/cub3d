/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:44:25 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/03 13:44:33 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static int	key_hook()
{

}

static int	mouse_hook()
{
	
}

void	get_event(t_data *data)
{
	mlx_key_hook(data->mlx.window, key_hook, data);
	mlx_mouse_hook(data->mlx.window, mouse_hook, data);
	mlx_loop(data->mlx.mlx_ptr);
}
