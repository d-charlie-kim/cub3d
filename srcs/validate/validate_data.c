/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:20 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/08 20:26:58 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "error.h"

static void	basic_check(t_data *data)
{
	if (!(data->textures.wall_east) || !(data->textures.wall_west) \
		|| !(data->textures.wall_north) || !(data->textures.wall_south))
		print_err_and_exit("Error\n : INVALID .cub FILE\n");
}

void	validate_data(t_data *data)
{
	basic_check(data);
	rgb_check(&(data->textures));
	texture_valid_check(&(data->textures));
	map_component_check(data->map_data);
	map_valid_check(data->map_data);
}
