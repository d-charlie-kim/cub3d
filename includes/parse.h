/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:23 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/09 15:08:23 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define NO	1
# define SO	2
# define WE	3
# define EA 4
# define F	5
# define C	6

void	init_data(t_data *data);
void	setting_textures(t_mlx *mlx, t_textures *textures);
void	setting_mlx(t_mlx *mlx);

void	file_name_check(char *str, char *str2);

void	put_map(t_data *data, char *line);
void	put_data(t_data *data, int id, char *line);

void	parsing(char **argv, t_data *data);

#endif
