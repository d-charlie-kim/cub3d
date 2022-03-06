/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:13:48 by jaejeong          #+#    #+#             */
/*   Updated: 2022/03/06 13:14:43 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# define OS 1 // 1 : window, 2 : mac

# if OS == 1
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
#  define W 119
#  define A 97
#  define S 115
#  define D 100
# elif OS == 2
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
# endif

# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define WHEEL_UP 4
# define WHEEL_DOWN 5

#endif
