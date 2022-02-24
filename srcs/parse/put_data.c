/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:37:02 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 21:17:32 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	get_color_value(int *texture, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	
}

void	put_data(t_data *data, int id, char *line)
{
	if (id == NO)
		data->textures.wall_north = ft_strdup(line);
	else if (id == SO)
		data->textures.wall_south = ft_strdup(line);
	else if (id == WE)
		data->textures.wall_west = ft_strdup(line);
	else if (id == EA)
		data->textures.wall_east = ft_strdup(line);
	else if (id == F)
		get_color_value(data->textures.floor, line);
	else
		get_color_value(data->textures.ceilling, line);
		
}

void	put_map(t_data *data, char *line)
{

}