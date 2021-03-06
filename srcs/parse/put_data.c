/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:37:02 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 16:46:31 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "structure.h"
#include "error.h"
#include "parse.h"

static int	checking(char *line, int *i, int *size, int *count)
{
	*size = 0;
	while (line[*i] == ' ')
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		(*size)++;
		(*i)++;
	}
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] == ',')
	{
		(*i)++;
		(*count)++;
		if ((*size) == 0 || (*size) > 3)
			return (1);
	}
	else if (line[*i])
		return (1);
	return (0);
}

static int	value_valid_check(char *line)
{
	int		i;
	int		size;
	int		count;

	i = 0;
	size = 0;
	count = 0;
	while (line[i])
	{
		if (checking(line, &i, &size, &count))
			return (1);
	}
	if (count != 2 || size == 0 || size > 3)
		return (1);
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
	while (line[i] && index < 3)
	{
		size = 0;
		while (line[i] && line[i] != ',')
		{
			i++;
			size++;
		}
		temp = (char *)malloc(sizeof(char) * (size + 1));
		if (!temp)
			print_err_and_exit("Error\n : CANT ALLOCATE MEMORY\n");
		ft_strlcpy(temp, line + i - size, size + 1);
		texture[index] = ft_atoi(temp);
		free(temp);
		index++;
		if (line[i] == ',')
			i++;
	}
}

void	put_data(t_data *data, int id, char *temp)
{
	char	*line;

	line = ft_strtrim(temp, " ");
	if (id == NO)
		data->textures.wall_north = ft_strdup(line);
	else if (id == SO)
		data->textures.wall_south = ft_strdup(line);
	else if (id == WE)
		data->textures.wall_west = ft_strdup(line);
	else if (id == EA)
		data->textures.wall_east = ft_strdup(line);
	else
	{
		if (value_valid_check(line))
			print_err_and_exit("Error\n : .cub FILE IS NOT VALID\n");
		if (id == F)
			get_color_value(data->textures.floor, line);
		else if (id == C)
			get_color_value(data->textures.ceilling, line);
	}
	free(line);
}

void	put_map(t_data *data, char *line)
{
	int		i;
	char	**new_map;

	i = 0;
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
	free(data->map_data);
	data->map_data = new_map;
}
