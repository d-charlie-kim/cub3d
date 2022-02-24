/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:29:23 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 18:01:43 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_H
# define MAPPING_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "struct.h"

void	ft_lst_add(t_map *lst);
void	map_name_check(char *str, char *str2);

void	map_parsing(char **argv, t_data *data);

#endif