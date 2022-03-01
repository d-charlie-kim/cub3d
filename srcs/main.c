/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:36 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 20:15:19 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include "validate.h"
#include "parse.h"
#include "error.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_err_and_exit("Error\n : ARGUMENTS ERROR\n");
	data_init(&data);
	parsing(argv, &data);
	// validate_data(&data);
	//draw
	return (0);
}
