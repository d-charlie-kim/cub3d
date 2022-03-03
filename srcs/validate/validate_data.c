/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:20 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 18:42:13 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include "error.h"
#include "libft.h"

static void	map_valid_check(char **map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data[i])
	{
		j = 0;
		while (map_data[i][j])
		{
			if (map_data[i][j] != ' ' && map_data[i][j] != '1')
			{
				if (i == 0 || map_data[i - 1][j] == ' ')
					print_err_and_exit("Error\n : MAP IS NOT CLOSED\n");
				else if (map_data[i + 1] == 0 || \
						ft_strlen(map_data[i + 1]) < (size_t)j + 1 || \
						map_data[i + 1][j] == ' ')
					print_err_and_exit("Error\n : MAP IS NOT CLOSED\n");
				else if (j == 0 || map_data[i][j - 1] == ' ')
					print_err_and_exit("Error\n : MAP IS NOT CLOSED\n");
				else if (map_data[i][j + 1] == 0 || map_data[i][j + 1] == ' ')
					print_err_and_exit("Error\n : MAP IS NOT CLOSED\n");
			}
			j++;
		}
		i++;
	}
}

static void	map_component_check(char **map_data)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map_data[i])
	{
		j = 0;
		while (map_data[i][j])
		{
			if (map_data[i][j] == 'E' || map_data[i][j] == 'W' || \
				map_data[i][j] == 'S' || map_data[i][j] == 'N')
				player_count++;
			else if (map_data[i][j] != ' ' && map_data[i][j] != '1' && \
				map_data[i][j] != '0')
				print_err_and_exit("Error\n : INVALID CHARACTER IN MAP\n");
			j++;
		}
		i++;
	}
	if (player_count == 0)
		print_err_and_exit("Error\n : NEED PLAYER IN MAP\n");
	else if (player_count > 1)
		print_err_and_exit("Error\n : TOO MANY PLAYER IN MAP\n");
}

static void	rgb_check(t_textures *textures)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (textures->ceilling[i] < 0 || textures->ceilling[i] > 255)
			print_err_and_exit("Error\n : INVALID CEILLING RGB\n");
		if (textures->floor[i] < 0 || textures->floor[i] > 255)
			print_err_and_exit("Error\n : INVALID FLOOR RGB\n");
		i++;
	}
}

static void	texture_valid_check(t_textures *textures)
{
	int	fd;

	fd = open(textures->wall_east, O_RDONLY);
	if (fd < 0)
		print_err_and_exit("Error\n : INVALID EAST TEXTURE\n");
	close(fd);
	fd = open(textures->wall_west, O_RDONLY);
	if (fd < 0)
		print_err_and_exit("Error\n : INVALID WEST TEXTURE\n");
	close(fd);
	fd = open(textures->wall_south, O_RDONLY);
	if (fd < 0)
		print_err_and_exit("Error\n : INVALID SOUTH TEXTURE\n");
	close(fd);
	fd = open(textures->wall_north, O_RDONLY);
	if (fd < 0)
		print_err_and_exit("Error\n : INVALID NORTH TEXTURE\n");
	close(fd);
}

void	validate_data(t_data *data)
{
	rgb_check(&(data->textures));
	texture_valid_check(&(data->textures));
	map_component_check(data->map_data);
	map_valid_check(data->map_data);
}
