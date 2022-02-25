/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:28:54 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 20:20:00 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	file_name_check(char *str, char *str2)
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
			print_err_and_exit("Error\n : MAP FILE IS NOT VALID");
		i--;
		j--;
	}
}
