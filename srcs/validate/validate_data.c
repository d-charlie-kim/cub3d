/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:20 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/07 19:17:59 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_data(t_data *data)
{
	rgb_check(&(data->textures));
	texture_valid_check(&(data->textures));
	map_component_check(data->map_data);
	map_valid_check(data->map_data);
}
