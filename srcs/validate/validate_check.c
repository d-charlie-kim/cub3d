/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:15:33 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 15:42:59 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "structure.h"
#include "error.h"
#include "libft.h"

static void	valid_checking(char **map_data, int i, int j)
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
}

void	map_valid_check(char **map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data[i])
	{
		j = 0;
		while (map_data[i][j])
		{
			valid_checking(map_data, i, j);
			j++;
		}
		i++;
	}
}

void	map_component_check(char **map_data)
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

void	rgb_check(t_textures *textures)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (textures->ceilling[i] < 0 || textures->ceilling[i] > 255)
			print_err_and_exit("Error\n : INVALID .cub FILE\n");
		if (textures->floor[i] < 0 || textures->floor[i] > 255)
			print_err_and_exit("Error\n : INVALID .cub FILE\n");
		i++;
	}
}

void	texture_valid_check(t_textures *textures)
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
