/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:30:55 by gchamore          #+#    #+#             */
/*   Updated: 2024/03/19 10:18:37 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

void	ft_error_handler(int i)
{
	if (i == 0)
	{
		ft_printf(" ❌ \033[1;31mError KILL\033[0m\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_printf(" ❌ \033[1;31mError SIGACTION\033[0m\n");
		exit(1);
	}
}
