/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:19:07 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 21:17:24 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"

void	data_init(t_data *data)
{
	int	i;

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
