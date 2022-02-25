/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:23 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/25 18:31:45 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "struct.h"
# include "error.h"
# include "libft.h"
#include "get_next_line.h"

# define NO	1
# define SO	2
# define WE	3
# define EA 4
# define F	5
# define C	6

void	data_init(t_data *data);

void	file_name_check(char *str, char *str2);

void	put_map(t_data *data, char *line);
void	put_data(t_data *data, int id, char *line);

void	parsing(char **argv, t_data *data);

#endif