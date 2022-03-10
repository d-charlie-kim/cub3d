/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejeong <jaejeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:16:38 by dokkim            #+#    #+#             */
/*   Updated: 2022/03/10 12:39:31 by jaejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "error.h"

void	print_err_and_exit(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}
