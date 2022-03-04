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

void	draw(t_data *data)
{
	set_player_position(data);
	show_image(data);     // jaejeong
	get_event(data);            // 나중에 같이
}
