/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:17:35 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 16:24:46 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*n_s1;
	unsigned char	*n_s2;

	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && !(*n_s1 == 0 && *n_s2 == 0))
	{
		if (*n_s1 != *n_s2)
			return (*n_s1 - *n_s2);
		n_s1++;
		n_s2++;
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	char	*temp;

	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	temp = dest;
	while (*s)
		*dest++ = *(char *)s++;
	*dest = 0;
	return (temp);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;

	n_dest = (unsigned char *)dest;
	n_src = (unsigned char *)src;
	if (!n_dest && !n_src)
		return (0);
	while (n--)
		*n_dest++ = *n_src++;
	return (dest);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	ngtv;
	int	num;

	i = 0;
	ngtv = 0;
	num = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		ngtv = 1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - 48;
		i++;
	}
	if (ngtv == 1)
		num *= -1;
	return (num);
}