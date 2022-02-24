/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:40 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 19:47:27 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"
#include "get_next_line.h"
#include "error.h"
#include <stdio.h>

static void	get_map(int fd, t_map *map_data)
{
	int		line_size;
	char	*str;
	t_map	*temp;

	line_size = 1;
	temp = map_data;
	while (line_size != 0)
	{
		str = NULL;
		line_size = get_next_line(fd, &str);
		if (line_size == -1)
			ft_error("Error\n : GNL ERROR");
		temp->line = str;
		temp->width = ft_strlen(str);
		temp->next = NULL;
		if (line_size != 0)
		{
			ft_lst_add(&(temp->next));
			temp = temp->next;
		}
	}
}

void	map_parsing(char **argv, t_data *data)
{
	int		fd;

	map_name_check(argv[1], ".cub");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\n : OPEN ERROR\n");
	ft_lst_add(&(data->map_data));
	get_map(fd, data->map_data);
}