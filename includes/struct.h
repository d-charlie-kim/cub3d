/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:21:29 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 17:56:06 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char			*line;
	long long		width;
	struct s_map	*next;
}	t_map;

typedef struct s_data
{
	t_map	*map_data; // 맵 담는 그릇 하나
	// t_draw or something // 그림 그릴 mlx 관련 그릇 하나
}	t_data;

#endif