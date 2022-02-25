/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:19:18 by jaejeong          #+#    #+#             */
/*   Updated: 2022/02/25 17:24:51 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_check(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	put_save_in_temp(char **temp, char **save)
{
	*temp = (char *)malloc(sizeof(char) * (ft_strlen(*save) + 1));
	if (!*temp)
		return (-1);
	ft_strlcpy(*temp, *save, ft_strlen(*save) + 1);
	free(*save);
	*save = NULL;
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*ret;

	jstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!jstr)
		return (NULL);
	ret = jstr;
	while (*s1)
		*jstr++ = *s1++;
	while (*s2)
		*jstr++ = *s2++;
	*jstr = '\0';
	return (ret);
}

int	zero_or_error(char **line, char *temp, int ret)
{
	if (ret == 0)
		return (zero_ret(line, temp));
	else if (ret == -1)
		return (-1);
	return (0);
}

int	error_free(char *first, char *second)
{
	free (first);
	free (second);
	return (-1);
}
