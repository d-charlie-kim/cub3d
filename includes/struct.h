/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:21:29 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 16:43:19 by dokkim           ###   ########.fr       */
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

typedef struct s_data
{
	t_textures	textures; // 텍스쳐 담는 그릇 하나
	char		**map_data; // 맵 담는 그릇 하나
	// t_mlx or something // 그림 그릴 mlx 관련 그릇 하나
}	t_data;

#endif