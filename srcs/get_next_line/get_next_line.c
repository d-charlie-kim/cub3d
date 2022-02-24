/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:18:14 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 18:30:58 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	ft_return_one(char **line, char **save, char *buffer, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	*line = (char *)malloc(ft_strlen(*save) + (sizeof(char) * (i + 1)));
	if (!(*line))
		gnl_error("Error\n : Malloc Error", NULL, *save);
	**line = '\0';
	ft_memcpy(*line, *save, ft_strlen(*save));
	ft_memcpy(*line, buffer, i);
	free(*save);
	*save = (char *)malloc(sizeof(char) * (size - i));
	if (!(*save))
		gnl_error("Error\n : Malloc Error", NULL, *line);
	**save = '\0';
	ft_memcpy(*save, buffer + i + 1, size - i - 1);
	return (1);
}

int	ft_return_zero(char **line, char **save, char *buffer, ssize_t size)
{
	*line = (char *)malloc(ft_strlen(*save) + (sizeof(char) * (size + 1)));
	if (!(*line))
		gnl_error("Error\n : Malloc Error", NULL, *save);
	**line = '\0';
	ft_memcpy(*line, *save, ft_strlen(*save));
	ft_memcpy(*line, buffer, size);
	free(*save);
	*save = NULL;
	return (0);
}

void	ft_repeat(char **temp, char **save, char *buffer, ssize_t size)
{
	*temp = (char *)malloc(ft_strlen(*save) + (sizeof(char) * (size + 1)));
	if (!(*temp))
		gnl_error("Error\n : Malloc Error", NULL, *save);
	**temp = '\0';
	ft_memcpy(*temp, *save, ft_strlen(*save));
	ft_memcpy(*temp, buffer, size);
	free(*save);
	*save = *temp;
}

int	ft_save(char **line, char **save)
{
	ssize_t	i;
	char	*temp;

	i = 0;
	while ((*save)[i] != '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (!(*line))
		gnl_error("Error\n : Malloc Error", NULL, *save);
	**line = '\0';
	ft_memcpy(*line, *save, i);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(*save) - i));
	if (!(temp))
		gnl_error("Error\n : Malloc Error", *line, *save);
	*temp = '\0';
	ft_memcpy(temp, *save + i + 1, ft_strlen(*save) - i - 1);
	free(*save);
	*save = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[1024];
	static char	*save = NULL;
	ssize_t		size;
	char		*temp;

	if (ft_check(save, ft_strlen(save)))
		return (ft_save(line, &save));
	size = 0;
	while (size >= 0)
	{
		size = read(fd, buffer, 1024);
		if (ft_check(buffer, size))
			return (ft_return_one(line, &save, buffer, size));
		if (size > 0)
			ft_repeat(&temp, &save, buffer, size);
		else if (size == 0)
			return (ft_return_zero(line, &save, buffer, size));
	}
	gnl_error("Error\n : GNL ERROR", NULL, save);
	return (-1);
}
