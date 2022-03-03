/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:21:29 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/03 14:06:15 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_t_textures
{
	char	*wall_north;
	char	*wall_east;
	char	*wall_south;
	char	*wall_west;
	int		floor[4];
	int		ceilling[4];
}	t_textures;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	void	*image;
	char	*image_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_data
{
	t_mlx		mlx;
	t_textures	textures; // 텍스쳐 담는 그릇 하나
	t_player	player;
	char		**map_data; // 맵 담는 그릇 하나
	// t_mlx or something // 그림 그릴 mlx 관련 그릇 하나
}	t_data;

#endif
