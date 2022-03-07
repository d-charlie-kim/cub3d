/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:01 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/07 18:53:00 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

# define WIDTH 900
# define HEIGHT 600

typedef struct s_ray
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

void	put_color_floor_and_ceilling(t_data *data);
void	draw(t_data *data);

void	draw_line(t_data *data, t_ray *ray, int x, double perp_wall_dist);

void	get_delta_distance(t_ray *ray);
void	get_side_distance(t_data *data, t_ray *ray);
void	player_movement(t_data *data, int key_code);
void	player_rotation(t_data *data, int key_code);

void	show_image(t_data *data);

void	create_new_image(t_mlx *mlx);
void	my_mlx_pixel_input(t_mlx *mlx, int x, int y, int color);
int		get_rgb_code(int color[4]);

#endif
