/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:28:54 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 19:24:26 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"
#include "error.h"

void	ft_lst_add(t_map **lst)
{
	*lst = (t_map *)malloc(sizeof(t_map));
	if (!(*lst))
		ft_error("Error\n : CANT ALLOCATE MEMORY\n");
	(*lst)->line = NULL;
	(*lst)->next = NULL;
	(*lst)->width = 0;
}

void	map_name_check(char *str, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (str[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (str[i] != str2[j])
			ft_error("Error\n : MAP FILE IS NOT VALID");
		i--;
		j--;
	}
}