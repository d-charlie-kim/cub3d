/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:16:38 by dokkim            #+#    #+#             */
/*   Updated: 2022/02/24 17:58:57 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "libft.h"

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (1);
}