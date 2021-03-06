/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:19:55 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 17:31:27 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "clear.h"
#include "structure.h"

static void	clear_map(t_data *data)
{
	int		i;
	char	**temp;

	i = 0;
	temp = data->map_data;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	data->map_data = NULL;
}

void	clear_all(t_data *data)
{
	clear_map(data);
	free(data->textures.wall_north);
	free(data->textures.wall_south);
	free(data->textures.wall_east);
	free(data->textures.wall_west);
	mlx_destroy_image(data->mlx.mlx_ptr, data->textures.tex_image[0]);
	mlx_destroy_image(data->mlx.mlx_ptr, data->textures.tex_image[1]);
	mlx_destroy_image(data->mlx.mlx_ptr, data->textures.tex_image[2]);
	mlx_destroy_image(data->mlx.mlx_ptr, data->textures.tex_image[3]);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.image);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window);
}
