/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:21:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 18:29:33 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_memcpy(char *dst, char *src, ssize_t n)
{
	ssize_t	i;
	ssize_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (j < n && src)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

int	ft_check(char *str, ssize_t size)
{
	ssize_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	gnl_error(char *str, char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	printf("%s\n", str);
	exit(-1);
}
