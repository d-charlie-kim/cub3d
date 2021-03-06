/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:40 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 16:27:34 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "error.h"
#include "structure.h"
#include "libft.h"
#include "parse.h"

static int	classify_data(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 0)
		return (0);
	else if (!ft_strncmp(line, "NO ", 3) && data->textures.wall_north == NULL)
		put_data(data, NO, line + i + 3);
	else if (!ft_strncmp(line, "SO ", 3) && data->textures.wall_south == NULL)
		put_data(data, SO, line + i + 3);
	else if (!ft_strncmp(line, "WE ", 3) && data->textures.wall_west == NULL)
		put_data(data, WE, line + i + 3);
	else if (!ft_strncmp(line, "EA ", 3) && data->textures.wall_east == NULL)
		put_data(data, EA, line + i + 3);
	else if (!ft_strncmp(line, "F ", 2) && data->textures.floor[0] == -1)
		put_data(data, F, line + i + 2);
	else if (!ft_strncmp(line, "C ", 2) && data->textures.ceilling[0] == -1)
		put_data(data, C, line + i + 2);
	else
		return (1);
	return (0);
}

static void	get_data(int fd, t_data *data)
{
	char	*line;
	int		ret;
	int		flag;

	line = NULL;
	ret = 1;
	flag = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			print_err_and_exit("Error\n : GNL ERROR\n");
		if (flag == 0)
			flag = classify_data(data, line);
		if (flag == 1)
			put_map(data, line);
		free(line);
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
}
