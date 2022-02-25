/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:37:02 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 16:54:05 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	get_color_value(int *texture, char *line)
{
	int		i;
	int		index;
	int		size;
	char	*temp;

	i = 0;
	index = 0;
	while (line[i])
	{
		size = 0;
		while (line[i] && line[i] != ',')
		{
			i++;
			size++;
		}
		temp = (int)malloc(sizeof(int) * (size + 1));
		temp = memcpy(temp, line + i - size, size);
		texture[index] = ft_atoi(temp);
		free (temp);
		index++;
	}
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