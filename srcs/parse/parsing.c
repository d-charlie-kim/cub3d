/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:40 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 18:43:18 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

static void	classify_data(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 0)
		return ;
	else if (line[i] == '1')
		put_map(data, line);
	else if (!ft_strncmp(line, "NO ", 3))
		put_data(data, NO, line + i + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		put_data(data, SO, line + i + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		put_data(data, WE, line + i + 3);
	else if (!ft_strncmp(line, "EA ", 3))
		put_data(data, EA, line + i + 3);
	else if (!ft_strncmp(line, "F ", 2))
		put_data(data, F, line + i + 2);
	else if (!ft_strncmp(line, "C ", 2))
		put_data(data, C, line + i + 2);
	else
		print_err_and_exit("Error\n : .cub FILE IS NOT VALID\n");
}

static void	get_data(int fd, t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			print_err_and_exit("Error\n : GNL ERROR\n");
		classify_data(data, line);
		free (line);
	}
}

void	print_test_code(t_data *data)
{
	printf("NO ::: %s\n", data->textures.wall_north);
	printf("SO ::: %s\n", data->textures.wall_south);
	printf("WE ::: %s\n", data->textures.wall_west);
	printf("EA ::: %s\n", data->textures.wall_east);
	printf("F :::: R : %d, G : %d, B : %d\n", data->textures.floor[0], data->textures.floor[1], data->textures.floor[2]);
	printf("C :::: R : %d, G : %d, B : %d\n", data->textures.ceilling[0], data->textures.ceilling[1], data->textures.ceilling[2]);

	int i = 0;
	while (data->map_data[i])
	{
		printf("MAP :::::::::: %s\n", data->map_data[i]);
		i++;
	}
}

void	parsing(char **argv, t_data *data)
{
	int		fd;

	file_name_check(argv[1], ".cub");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err_and_exit("Error\n : OPEN ERROR\n");
	get_data(fd, data);
	print_test_code(data);
}