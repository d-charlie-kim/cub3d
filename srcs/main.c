/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:57:36 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 16:23:19 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	main(int argc, char **argv)
{
	//t_data	data;

	if (argc != 2)
		ft_error("Error\n : Arguments error\n");
	//data_init(&data);
	mapping(argv, &data);
	map_validate(&data);
	//draw
	return (0);
}