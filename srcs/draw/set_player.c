/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:38:03 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/07 18:59:06 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "struct.h"
#include "event.h"

static void	find_player(char ***map_data, char *dir, int *x, int *y)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = *map_data;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || \
				map[i][j] == 'W' || map[i][j] == 'S')
			{
				*dir = map[i][j];
				map[i][j] = 0;
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1.0;
	}
	else if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1.0;
	}
	else if (dir == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0;
	}
	else if (dir == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0;
	}
}

static void	set_player_plane(t_player *player)
{
	if (player->dir_x == 0)
	{
		player->plane_y = 0;
		player->plane_x = player->dir_y * (-0.66);
	}
	else if (player->dir_y == 0)
	{
		player->plane_x = 0;
		player->plane_y = player->dir_x * (0.66);
	}
}

void	set_player_position(t_data *data)
{
	char	dir;
	int		x;
	int		y;

	find_player(&(data->map_data), &dir, &x, &y);
	set_player_dir(&(data->player), dir);
	set_player_plane(&(data->player));
	data->player.pos_x = (double)x + 0.5;
	data->player.pos_y = (double)y + 0.5;
}
