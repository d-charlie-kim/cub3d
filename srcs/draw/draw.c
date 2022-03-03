/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:17 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/03 14:07:18 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "struct.h"
#include "event.h"

static void	set_player_position(t_data *data)
{
	char	dir;
	int		x;
	int		y;

	find_player_and_dir(&dir, &x, &y);
	set_player_dir(&(data->player), dir);
	data->player.pos_x = (double)x + 0.5;
	data->player.pos_y = (double)y + 0.5;
}

void	draw(t_data *data)
{
	set_player_position(data);
	make_first_image(data);
	get_event(data);
}
