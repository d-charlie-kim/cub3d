/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:37:02 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 18:37:28 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

static int	value_valid_check(char *line)
{
	int	i;

	i = 0;
	/*
		1. 숫자와 콤마 그리고 공백으로만 이루어져있는지 체크
		2. 숫자가 255 범위 내에 있는지 사전 체크(자리수만 체크)
	*/
	return (0);
}

static void	get_color_value(int *texture, char *line)
{
	int		i;
	int		index;
	int		size;
	char	*temp;

	i = 0;
	index = 0;
	if (value_valid_check(line))
		print_err_and_exit("Error\n : .cub FILE IS NOT VALID\n");
	while (line[i] && index < 3)
	{
		size = 0;
		while (line[i] && line[i] != ',')
		{
			i++;
			size++;
		}
		temp = (char *)malloc(sizeof(char) * (size));
		if (!temp)
			print_err_and_exit("Error\n : CANT ALLOCATE MEMORY\n");
		ft_strlcpy(temp, line + i - size, size + 1);
		texture[index] = ft_atoi(temp);
		free (temp);
		index++;
		if (line[i] == ',')
			i++;
	}
}

void	put_data(t_data *data, int id, char *line)
{
	while (*line == ' ')
		line++;
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
	int		i;
	char	**new_map;

	i = 0;
	while (data->map_data && data->map_data[i])
		i++;
	new_map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		print_err_and_exit("Error\n : CANT ALLOCATE MEMORY\n");
	new_map[i + 1] = 0;
	new_map[i] = ft_strdup(line);
	i--;
	while (i >= 0)
	{
		new_map[i] = (data->map_data)[i];
		i--;
	}
	free (data->map_data);
	data->map_data = new_map;
}
