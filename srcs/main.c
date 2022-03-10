/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:36 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 12:38:32 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "validate.h"
#include "parse.h"
#include "error.h"
#include "draw.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_err_and_exit("Error\n : ARGUMENTS ERROR\n");
	init_data(&data);
	parsing(argv, &data);
	validate_data(&data);
	setting_mlx(&(data.mlx));
	setting_textures(&(data.mlx), &(data.textures));
	draw(&data);
	return (0);
}
