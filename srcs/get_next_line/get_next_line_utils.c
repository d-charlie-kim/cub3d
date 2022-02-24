/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:21:03 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 17:40:57 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	write (1, str, ft_strlen(str));
	write (1, "\n", 1);
	exit(-1);
}
