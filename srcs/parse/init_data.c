/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:19:07 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/09 15:12:47 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <mlx.h>
#include "struct.h"
#include "draw.h"

void	setting_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	mlx->image = NULL;
}

void	setting_textures(t_mlx *mlx, t_textures *textures)
{
	textures->tex_image[NORTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	textures->wall_north, &(textures->tex_width[NORTH]), \
	&(textures->tex_height[NORTH]));
	textures->tex_image[SOUTH] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	textures->wall_south, &(textures->tex_width[SOUTH]), \
	&(textures->tex_height[SOUTH]));
	textures->tex_image[EAST] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	textures->wall_east, &(textures->tex_width[EAST]), \
	&(textures->tex_height[EAST]));
	textures->tex_image[WEST] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	textures->wall_west, &(textures->tex_width[WEST]), \
	&(textures->tex_height[WEST]));
	textures->tex[NORTH] = mlx_get_data_addr(textures->tex_image[NORTH], \
	&(textures->bits_per_pixel[NORTH]), &(textures->line_size[NORTH]), \
	&(textures->endian[NORTH]));
	textures->tex[SOUTH] = mlx_get_data_addr(textures->tex_image[SOUTH], \
	&(textures->bits_per_pixel[SOUTH]), &(textures->line_size[SOUTH]), \
	&(textures->endian[SOUTH]));
	textures->tex[EAST] = mlx_get_data_addr(textures->tex_image[EAST], \
	&(textures->bits_per_pixel[EAST]), &(textures->line_size[EAST]), \
	&(textures->endian[EAST]));
	textures->tex[WEST] = mlx_get_data_addr(textures->tex_image[WEST], \
	&(textures->bits_per_pixel[WEST]), &(textures->line_size[WEST]), \
	&(textures->endian[WEST]));
}
/*
	나중에 destroy 해줘야함!!!!!!!!!
*/

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->textures.floor[i] = -1;
		data->textures.ceilling[i] = -1;
		i++;
	}
	data->map_data = NULL;
}
