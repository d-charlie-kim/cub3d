/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:23 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 15:15:51 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "structure.h"

void	validate_data(t_data *data);

void	texture_valid_check(t_textures *textures);
void	rgb_check(t_textures *textures);
void	map_component_check(char **map_data);
void	map_valid_check(char **map_data);

#endif
