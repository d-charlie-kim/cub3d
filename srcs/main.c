/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:36 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 17:57:53 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include "init.h"
#include "mapping.h"
#include "error.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error("Error\n : ARGUMENTS ERROR\n");
	//data_init(&data);
	map_parsing(argv, &data);
	t_map *temp;
	temp = data.map_data;
	while (temp != NULL)
	{
		printf("::  %s  ::\n", temp->line);
		temp = temp->next;
	}
	//map_validate(&data);
	//draw
	return (0);
}