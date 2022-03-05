/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:16:55 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/05 12:49:38 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "draw.h"
#include <mlx.h>

void	create_new_image(t_mlx *mlx)
{
	if (mlx->image)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	mlx->image = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->image_addr = mlx_get_data_addr(mlx->image, &(mlx->bits_per_pixel),
			&(mlx->line_size), &(mlx->endian));
}

void	my_mlx_pixel_input(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel_point;

	pixel_point = mlx->image_addr
		+ (y * mlx->line_size + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)pixel_point = color;
}

int	get_rgb_code(int color[4])
{
	int	ret;

	ret = 0;
	ret += color[0];
	ret <<= 8;
	ret += color[1];
	ret <<= 8;
	ret += color[2];
	return (ret);
}
