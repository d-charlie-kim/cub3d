/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:01 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/03 13:46:57 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

# define WIDTH 900
# define HEIGHT 600

void	draw(t_data *data);

void	create_new_image(t_mlx *mlx);
void	my_mlx_pixel_input(t_mlx *mlx, int x, int y, int color);

void	show_image(t_data *data);

#endif
