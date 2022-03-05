/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:01 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/05 10:44:54 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

# define WIDTH 900
# define HEIGHT 600

typedef struct	s_ray
{
	int		side;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}	t_ray;

void	set_player_position(t_data *data);

void	draw_line(t_mlx *mlx, t_ray *ray, int x, double distance);
void	draw(t_data *data);

void	calculate_delta_distance(t_ray *ray);
void	calculate_side_distance(t_data *data, t_ray *ray);

void	show_image(t_data *data);

void	create_new_image(t_mlx *mlx);
void	my_mlx_pixel_input(t_mlx *mlx, int x, int y, int color);

#endif
