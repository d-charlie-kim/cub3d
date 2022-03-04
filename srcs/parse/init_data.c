/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:19:07 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/03 13:23:13 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "struct.h"
#include "draw.h"
#include "../../minilibx_opengl_20191021/mlx.h"

static void	setting_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		exit(ENOMEM);
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	if (!(mlx->window))
		exit(ENOMEM);
}

void	init_data(t_data *data)
{
	int	i;

	setting_mlx(&(data->mlx));
	data->textures.wall_north = 0;
	data->textures.wall_east = 0;
	data->textures.wall_west = 0;
	data->textures.wall_south = 0;
	i = 0;
	while (i < 4)
	{
		data->textures.floor[i] = 0;
		data->textures.ceilling[i] = 0;
		i++;
	}
	data->map_data = NULL;
}
